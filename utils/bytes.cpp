#ifndef INTRO_UTILS_BYTES_CPP_INCLUDED
#define INTRO_UTILS_BYTES_CPP_INCLUDED

#include <sstream>
#include <iomanip>
#include <cstdint>

using namespace std;

inline string bytes2String(vector<uint8_t> const& msg) {
    stringstream ss;
    ss << hex << setfill('0');
    for (const auto& byte : msg) {
        ss << setw(2) << static_cast<int>(byte);
    }
    return ss.str();
}

inline vector<uint8_t> string2Bytes(string const& str) {
    vector<uint8_t> bytes;
    bytes.reserve(str.length() / 2);

    for (size_t i = 0; i < str.length(); i += 2) {
        string byteString = str.substr(i, 2);
        uint8_t byte = static_cast<uint8_t>(strtol(byteString.c_str(), nullptr, 16));
        bytes.push_back(byte);
    }

    return bytes;
}

#endif