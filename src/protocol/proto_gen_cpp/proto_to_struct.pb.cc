// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto_to_struct.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto_to_struct.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {


}  // namespace


void protobuf_AssignDesc_proto_5fto_5fstruct_2eproto() {
  protobuf_AddDesc_proto_5fto_5fstruct_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto_to_struct.proto");
  GOOGLE_CHECK(file != NULL);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_5fto_5fstruct_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_proto_5fto_5fstruct_2eproto() {
}

void protobuf_AddDesc_proto_5fto_5fstruct_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::protobuf_AddDesc_google_2fprotobuf_2fdescriptor_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\025proto_to_struct.proto\032 google/protobuf"
    "/descriptor.proto:7\n\017string_max_size\022\035.g"
    "oogle.protobuf.FieldOptions\030\221N \001(\005:9\n\021re"
    "peated_max_size\022\035.google.protobuf.FieldO"
    "ptions\030\222N \001(\005::\n\017parse_to_struct\022\037.googl"
    "e.protobuf.MessageOptions\030\241\234\001 \001(\010", 233);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto_to_struct.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::google::protobuf::FieldOptions::default_instance(),
    10001, 5, false, false);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::google::protobuf::FieldOptions::default_instance(),
    10002, 5, false, false);
  ::google::protobuf::internal::ExtensionSet::RegisterExtension(
    &::google::protobuf::MessageOptions::default_instance(),
    20001, 8, false, false);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_5fto_5fstruct_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_5fto_5fstruct_2eproto {
  StaticDescriptorInitializer_proto_5fto_5fstruct_2eproto() {
    protobuf_AddDesc_proto_5fto_5fstruct_2eproto();
  }
} static_descriptor_initializer_proto_5fto_5fstruct_2eproto_;
::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FieldOptions,
    ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 >, 5, false >
  string_max_size(kStringMaxSizeFieldNumber, 0);
::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FieldOptions,
    ::google::protobuf::internal::PrimitiveTypeTraits< ::google::protobuf::int32 >, 5, false >
  repeated_max_size(kRepeatedMaxSizeFieldNumber, 0);
::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MessageOptions,
    ::google::protobuf::internal::PrimitiveTypeTraits< bool >, 8, false >
  parse_to_struct(kParseToStructFieldNumber, false);

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
