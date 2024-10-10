#ifndef INTRO_LIBS_LOGGER_CPP_INCLUDED
#define INTRO_LIBS_LOGGER_CPP_INCLUDED

#include "./logger.h"

Logger::Logger(string const& _file_name, bool _quiet_mode) {
    file = File();
    file_name = _file_name;
    quiet_mode = _quiet_mode;
}

void Logger::log(string const& msg) {
    file.save(msg, file_name);
    if (!quiet_mode) cout << msg << endl;
}

#endif