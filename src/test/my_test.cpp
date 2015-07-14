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

#include "proto_to_struct.pb.h"
#include "comm_struct.pb.h"
#include "comm_struct_struct.h"

using namespace std;

int main(int argc, char* argv[])
{
    ProtoComm::Player::HeroInfo hero_info;
    HeroInfoStruct hero_info_struct;

    hero_info.set_id(1001);
    hero_info.set_level(10);

    ConvPrimitiveProtoToStruct(&hero_info, &hero_info_struct);

    cout << "hero_info_struct.id = " << hero_info_struct.id << endl;
    cout << "hero_info_struct.level = " << hero_info_struct.level << endl;

    return 0;
}