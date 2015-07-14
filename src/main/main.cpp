#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "google/protobuf/message.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/descriptor.pb.h"
#include "google/protobuf/dynamic_message.h"
#include "google/protobuf/compiler/importer.h"

#include "proto_to_struct.pb.h"
#include "comm_struct.pb.h"

using namespace google::protobuf;
using namespace google::protobuf::compiler;
using google::protobuf::Message;
using namespace std;

typedef map<string, const FileDescriptor*> FileDescMap;

class FileErrorCollector : public MultiFileErrorCollector {
public:
    void AddError(const string& filename, int line, int column, const string& message) {
        cout << "filename: " << filename << endl;
        cout << "line: " << line << endl;
        cout << "column: " << column << endl;
        cout << "message: " << message << endl;
    }
};

const char* TimeName(time_t t)
{
    static char time_stamp[64] = { 0 };
    strftime(time_stamp, sizeof(time_stamp),
        "%Y-%m-%d %H:%M:%S", localtime(&t));
    return (const char*)time_stamp;
}

const char* CurTimeName()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return TimeName(tv.tv_sec);
}

int32_t ParseParam(int32_t argc, char* argv[], vector<string>& include_path_vec, vector<string>& proto_file_vec, string& out_path)
{
    static struct option long_options[] = {
        { "include_path", 1, NULL, 'I' },
        { "proto_file", 1, NULL, 'P' },
        { "out_path", 1, NULL, 'O' },
        { 0, 0, 0, 0 }
    };

    int32_t opt;
    while (-1 != (opt = getopt_long(argc, argv, "I:P:O:", long_options, NULL))) {
        switch (opt) {
        case 'I': {
                      include_path_vec.push_back(optarg);
                      break;
        }
        case 'P': {
                      proto_file_vec.push_back(optarg);
                      break;
        }
        case 'O': {
                      out_path = optarg;
                      break;
        }
        default: {
                     cout << "Usage: " << argv[0] << "-I include_path -P proto_file -O out_path" << endl;
                     return -1;
        }
        }
    }
    return 0;
}

void MapPathToDiskSourceTree(DiskSourceTree& src_tree, vector<string>& include_path_vec)
{
    for (uint32_t i = 0; i < include_path_vec.size(); i++) {
        src_tree.MapPath("", include_path_vec[i]);
    }
    return;
}

int32_t ParseProtoFileDesc(Importer* importer, vector<string>& proto_file_vec, FileDescMap& file_desc_map)
{
    for (uint32_t i = 0; i < proto_file_vec.size(); i++) {
        const FileDescriptor* file_desc = importer->Import(proto_file_vec[i]);
        if (file_desc == NULL) {
            cout << "import[" << proto_file_vec[i] << "] error!" << endl;
            return -1;
        }

        int32_t count = file_desc->message_type_count();
        if (count <= 0) {
            continue;
        }

        // 该文件中有一个需要要解析的message，都添加到FileDescMap中
        for (int j = 0; j < count; j++) {
            const Descriptor* msg_desc = file_desc->message_type(j);
            bool m = msg_desc->options().GetExtension(parse_to_struct);
            if (m == true) {
                file_desc_map.insert(FileDescMap::value_type(proto_file_vec[i], file_desc));
                break;
            }
        }
    }
    return 0;
}

void ParseToken(const char* str, const char* seq, vector<string>& out_vec)
{
    static char buf[4096] = { 0 };
    strncpy(buf, str, sizeof(buf));

    char *token = strtok(buf, seq);

    while (token != NULL) {
        out_vec.push_back(token);
        token = strtok(NULL, seq);
    }
}

string GetRidOfExtName(const string& file_name)
{
    vector<string> token;
    ParseToken(file_name.c_str(), ".", token);
    if (token.size() > 0)
        return token[0];
    else
        return string("");
}

string ConvProtoNamespaceToCpp(const string& package)
{
    vector<string> token;
    ParseToken(package.c_str(), ".", token);
    if (token.size() > 0) {
        string name;
        for (uint32_t i = 0; i < token.size() - 1; i++) {
            name += token[i] + "::";
        }
        name += token[token.size() - 1];
        return name;
    } else {
        return string("");
    }
}

string GetStructFileName(const FileDescriptor* file_desc)
{
    string name;
    name = GetRidOfExtName(file_desc->name()) + "_struct.h";
    transform(name.begin(), name.end(), name.begin(), (int(*)(int))tolower);
    return name;
}

string GetStructFileFullName(string& out_path, const FileDescriptor* file_desc)
{
    string name = GetStructFileName(file_desc);
    if (out_path.size() == 0)
        return name;
    string full_name = out_path + "/" + name;
    return full_name;
}

string GetStructName(const Descriptor* msg_desc)
{
    string name;
    name = msg_desc->name() + "Struct";
    return name;
}

string GetStringMaxSize(const FieldDescriptor* field_desc)
{
    string name = field_desc->lowercase_name();
    transform(name.begin(), name.end(), name.begin(), (int(*)(int))toupper);
    name += "_STRING_MAX_SIZE";
    return name;
}

string GetRepeatedMaxSize(const FieldDescriptor* field_desc)
{
    string name = field_desc->lowercase_name();
    transform(name.begin(), name.end(), name.begin(), (int(*)(int))toupper);
    name += "_REPEATED_MAX_SIZE";
    return name;
}

void AddFileComments(const FileDescriptor* file_desc, ostringstream& str)
{
    str << "/**" << endl;
    str << "* @file " << GetStructFileName(file_desc) << endl;
    str << "* @brief auto generated by " << file_desc->name() << endl;
    str << "* @author fergus <zfengzhen@gmail.com>" << endl;
    str << "* @date " << CurTimeName() << endl;
    str << "*/\n\n" << endl;
}

void ParseInclude(const FileDescriptor* file_desc, FileDescMap& file_desc_map, ostringstream& str)
{
    str << "#pragma once\n\n" << endl;
    str << "using namespace " << ConvProtoNamespaceToCpp(file_desc->package()) << ";\n\n" << endl;

    // 解析是否依赖其他struct文件
    int32_t count = file_desc->dependency_count();
    for (int i = 0; i < count; i++) {
        const FileDescriptor* depend_file_desc = file_desc->dependency(i);
        FileDescMap::iterator it = file_desc_map.find(depend_file_desc->name());
        if (it != file_desc_map.end()) {
            string include_prex = GetRidOfExtName(depend_file_desc->name().c_str());
            str << "#include <" << include_prex << "_struct.h>" << endl;
        }
    }

    str << "#include <" << GetRidOfExtName(file_desc->name()) << ".pb.h>" << endl;
    str << "#include <string.h>" << endl;
    str << "\n\n";
}

void ParseDefineMaxSize(const FileDescriptor* file_desc, ostringstream& str)
{
    int32_t count = file_desc->message_type_count();
    for (int i = 0; i < count; i++) {
        const Descriptor* msg_desc = file_desc->message_type(i);
        bool need_parse = msg_desc->options().GetExtension(parse_to_struct);
        if (need_parse == true) {
            int32_t field_count = msg_desc->field_count();
            for (int32_t j = 0; j < field_count; j++) {
                const FieldDescriptor* field_desc = msg_desc->field(j);
                FieldDescriptor::CppType cpp_type = field_desc->cpp_type();
                FieldDescriptor::Label label = field_desc->label();
                // 字符串最大值
                if (cpp_type == FieldDescriptor::CPPTYPE_STRING) {
                    const FieldOptions& field_options = field_desc->options();
                    if (field_options.HasExtension(string_max_size)) {
                        str << "#define " << GetStringMaxSize(field_desc) << " " << field_options.GetExtension(string_max_size) << endl;
                    } else {
                        str << endl << field_desc->name() << " is string but not has string_max_size!" << endl;
                        return;
                    }
                }
                // repeated最大值
                if (label == FieldDescriptor::LABEL_REPEATED) {
                    const FieldOptions& field_options = field_desc->options();
                    if (field_options.HasExtension(repeated_max_size)) {
                        str << "#define " << GetRepeatedMaxSize(field_desc) << " " << field_options.GetExtension(repeated_max_size) << endl;
                    } else {
                        str << endl << field_desc->name() << " is repeated but not has repeated_max_size!" << endl;
                        return;
                    }
                }
            }
        } // need_parse
    }
    str << "\n\n";
}

void ParseField(const FieldDescriptor* field_desc, ostringstream& str)
{
    SourceLocation src_loc;
    field_desc->GetSourceLocation(&src_loc);
    if (src_loc.leading_comments.empty() == false)
        str << "\t// " << src_loc.leading_comments;
    str << "\t";
    string field_name = field_desc->lowercase_name();
    FieldDescriptor::CppType cpp_type = field_desc->cpp_type();
    if (cpp_type == FieldDescriptor::CPPTYPE_INT32) {
        str << "int32_t " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_INT64) {
        str << "int64_t " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_UINT32) {
        str << "uint32_t " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_UINT64) {
        str << "uint64_t " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_DOUBLE) {
        str << "double " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_FLOAT) {
        str << "float " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_BOOL) {
        str << "bool " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_ENUM) {
        str << "int32_t " << field_name;
    } else if (cpp_type == FieldDescriptor::CPPTYPE_STRING) {
        str << "char " << field_name;
        str << "[" << GetStringMaxSize(field_desc) << "]";
    } else if (cpp_type == FieldDescriptor::CPPTYPE_MESSAGE) {
        const Descriptor* msg_desc = field_desc->message_type();
        str << GetStructName(msg_desc) << " " << field_name;
    } else {
        str << endl << field_name << " CppType error!" << endl;
        return;
    }

    FieldDescriptor::Label label = field_desc->label();
    if (label == FieldDescriptor::LABEL_REPEATED) {
        str << "[" << GetRepeatedMaxSize(field_desc) << "]";
    }

    if (src_loc.trailing_comments.empty() == false)
        str << "; // " << src_loc.trailing_comments;
    else
        str << ";" << endl;
}

bool NeedParseAssign(const Descriptor* msg_desc)
{
    int32_t field_count = msg_desc->field_count();
    for (int32_t j = 0; j < field_count; j++) {
        const FieldDescriptor* field_desc = msg_desc->field(j);
        FieldDescriptor::CppType cpp_type = field_desc->cpp_type();
        FieldDescriptor::Label label = field_desc->label();

        if (cpp_type != FieldDescriptor::CPPTYPE_MESSAGE
            && label != FieldDescriptor::LABEL_REPEATED
            ) {
            return true;
        }
    }
    return false;
}

void ParseAssignStructToProto(const FieldDescriptor* field_desc, ostringstream& str)
{
    FieldDescriptor::CppType cpp_type = field_desc->cpp_type();
    FieldDescriptor::Label label = field_desc->label();
    string field_name = field_desc->lowercase_name();

    if (cpp_type != FieldDescriptor::CPPTYPE_MESSAGE
        && label != FieldDescriptor::LABEL_REPEATED
        ) {
        // 原始类型非repeated变量
        str << "\tproto->set_" << field_name << "(sct->" << field_name << ");" << endl;
    }
}

void ParseAssignProtoToStruct(const FieldDescriptor* field_desc, ostringstream& str)
{
    FieldDescriptor::CppType cpp_type = field_desc->cpp_type();
    FieldDescriptor::Label label = field_desc->label();
    string field_name = field_desc->lowercase_name();

    if (cpp_type != FieldDescriptor::CPPTYPE_MESSAGE
        && cpp_type != FieldDescriptor::CPPTYPE_STRING
        && label != FieldDescriptor::LABEL_REPEATED
        ) {
        // 原始类型非repeated变量
        str  << "\tsct->" << field_name << " = proto->" << field_name << "();\n";
    }

    if (cpp_type == FieldDescriptor::CPPTYPE_STRING
        && label != FieldDescriptor::LABEL_REPEATED
        ) {
        // 原始类型非repeated变量
        str << "\tstrncpy(sct->" << field_name << ", proto->" << field_name << "().c_str(), " << GetStringMaxSize(field_desc) << ");\n";
    }
}

void ParseMessage(const FileDescriptor* file_desc, ostringstream& str)
{
    int32_t count = file_desc->message_type_count();
    for (int i = 0; i < count; i++) {
        const Descriptor* msg_desc = file_desc->message_type(i);
        bool need_parse = msg_desc->options().GetExtension(parse_to_struct);
        if (need_parse == true) {
            SourceLocation src_loc;
            msg_desc->GetSourceLocation(&src_loc);
            if (src_loc.leading_comments.empty() == false)
                str << "// " << src_loc.leading_comments;
            str << "typedef struct " << msg_desc->name() << "_struct {" << endl;
            int32_t field_count = msg_desc->field_count();
            for (int32_t j = 0; j < field_count; j++) {
                const FieldDescriptor* field_desc = msg_desc->field(j);
                ParseField(field_desc, str);
            }
            str << "} " << GetStructName(msg_desc) << ";\n\n" << endl;
        }
    }
}

void ParseFuncStructToProto(const FileDescriptor* file_desc, ostringstream& str)
{
    int32_t count = file_desc->message_type_count();
    for (int i = 0; i < count; i++) {
        const Descriptor* msg_desc = file_desc->message_type(i);
        bool need_parse = msg_desc->options().GetExtension(parse_to_struct);
        if (need_parse == true && NeedParseAssign(msg_desc) == true) {
            str << "void ConvPrimitiveStructToProto(" << GetStructName(msg_desc) << "* sct, " << msg_desc->name() << "* proto)\n{" << endl;
            int32_t field_count = msg_desc->field_count();
            for (int32_t j = 0; j < field_count; j++) {
                const FieldDescriptor* field_desc = msg_desc->field(j);
                ParseAssignStructToProto(field_desc, str);
            }
            str << "}\n\n" << endl;
        }
    }
}

void ParseFuncProtoToStruct(const FileDescriptor* file_desc, ostringstream& str)
{
    int32_t count = file_desc->message_type_count();
    for (int i = 0; i < count; i++) {
        const Descriptor* msg_desc = file_desc->message_type(i);
        bool need_parse = msg_desc->options().GetExtension(parse_to_struct);
        if (need_parse == true && NeedParseAssign(msg_desc) == true) {
            str << "void ConvPrimitiveProtoToStruct(" << msg_desc->name() << "* proto, " << GetStructName(msg_desc) << "* sct)\n{" << endl;
            int32_t field_count = msg_desc->field_count();
            for (int32_t j = 0; j < field_count; j++) {
                const FieldDescriptor* field_desc = msg_desc->field(j);
                ParseAssignProtoToStruct(field_desc, str);
            }
            str << "}\n\n" << endl;
        }
    }
}


int main(int argc, char* argv[])
{
    vector<string> include_path_vec;
    vector<string> proto_file_vec;
    string out_path;
    DiskSourceTree src_tree;
    FileErrorCollector err_collector;
    Importer* importer = NULL;
    FileDescMap file_desc_map;
    int32_t ret = 0;

    // 解析参数
    ret = ParseParam(argc, argv, include_path_vec, proto_file_vec, out_path);
    if (ret != 0 || proto_file_vec.size() == 0) {
        cout << "ret = " << ret << " proto_file_vec.size() = " << proto_file_vec.size() << endl;
        return -1;
    }

    // 添加搜索路径
    MapPathToDiskSourceTree(src_tree, include_path_vec);

    // 初始化Improter
    importer = new Importer(&src_tree, &err_collector);

    // 分析要解析的文件
    ret = ParseProtoFileDesc(importer, proto_file_vec, file_desc_map);
    if (ret != 0) return -1;

    // 遍历文件，找出需要解析的proto文件
    for (FileDescMap::iterator it = file_desc_map.begin(); it != file_desc_map.end(); ++it) {
        const FileDescriptor* file_desc = it->second;
        ostringstream struct_str;
        AddFileComments(file_desc, struct_str);
        ParseInclude(file_desc, file_desc_map, struct_str);
        ParseDefineMaxSize(file_desc, struct_str);
        ParseMessage(file_desc, struct_str);
        ParseFuncStructToProto(file_desc, struct_str);
        ParseFuncProtoToStruct(file_desc, struct_str);
        string file_name = GetStructFileFullName(out_path, file_desc);
        int32_t fd = open(file_name.c_str(), O_RDWR | O_CREAT | O_TRUNC, 0666);
        if (fd < 0) {
            cout << "open [" << file_name << "] error!" << endl;
            return -1;
        }
        write(fd, struct_str.str().c_str(), struct_str.str().size());
        close(fd);
    }

    ProtoComm::Player::HeroInfo hero_info;
    hero_info.set_id(1001);
    cout << hero_info.DebugString() << endl;
    return 0;
}