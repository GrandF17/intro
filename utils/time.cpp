#ifndef INTRO_UTILS_TIME_CPP_INCLUDED
#define INTRO_UTILS_TIME_CPP_INCLUDED

#include <string.h>
#include <time.h>

#include <cstdint>
#include <string>

inline std::string timestamp() {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    char date[80];
    strftime(date, 80, "[%Y-%m-%d %X] ", localTime);

    return date;
}

#endif