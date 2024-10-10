#ifndef INTRO_LIBS_LOGGER_H_INCLUDED
#define INTRO_LIBS_LOGGER_H_INCLUDED

#include <iostream>

#include "./file.h"
#include "../utils/bytes.cpp"

using namespace std;

class Logger {
    File file;
    string file_name;
    bool quiet_mode;

    public:
     Logger(string const& _file_name, bool _quiet_mode = false);
     void log(string const& msg);
};

#endif