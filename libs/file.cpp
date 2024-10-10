#ifndef INTRO_LIBS_FILE_CPP_INCLUDED
#define INTRO_LIBS_FILE_CPP_INCLUDED

#include "./file.h"

using namespace std;

File::ReadRet File::read(string file_name) {
    vector<uint8_t> data;
    ifstream myfile(file_name, ios::binary);

    if (!myfile.is_open()) {
        File::Status status{ false, "Error: Failed to open " + file_name };
        File::ReadRet ret{ data, status };
        return ret;
    }

    data.assign((istreambuf_iterator<char>(myfile)), istreambuf_iterator<char>());
    if (myfile.bad()) {
        myfile.close();
        File::Status status{ false, "Error: Failed to read " + file_name };
        File::ReadRet ret{ data, status };
        return ret;
    }

    myfile.close();
    if (myfile.is_open()) {
        File::Status status{ false, "Error : Failed to close " + file_name };
        File::ReadRet ret{ data, status };
        return ret;
    }

    File::Status status{ true, "Ok" };
    File::ReadRet ret{ data, status };
    return ret;
}

File::WriteRet File::save(/**vector<uint8_t> */string const& data, string file_name) {
    ofstream outfile(file_name, ios::out | ios::binary | std::ios_base::app);
    if (!outfile.is_open()) {
        File::Status status{ 
            false,
            "Error: Failed to open file " +
            file_name +
            " for writing" 
        };
        File::WriteRet ret{ status };
        return ret;
    }

    // outfile.write(reinterpret_cast<char*>(&data[0]), data.size());
    outfile << data << endl;
    if (outfile.bad()) {
        outfile.close();
        File::Status status{ false, "Error: Failed to write to " + file_name};
        File::WriteRet ret{ status };
        return ret;
    }

    outfile.close();
    if (outfile.is_open()) {
        File::Status status{ false, "Error: Failed to close " + file_name};
        File::WriteRet ret{ status };
        return ret;
    }

    File::Status status{ true, "Ok"};
    File::WriteRet ret{ status };
    return ret;
}

File::WriteRet File::clean(string file_name) {
    ofstream outfile(file_name, ios::out | ios::trunc);
    if (!outfile.is_open()) {
        File::Status status{ 
            false,
            "Error: Failed to open file " +
            file_name +
            " to clean it" 
        };
        File::WriteRet ret{ status };
        return ret;
    }

    outfile.close();
    if (outfile.is_open()) {
        File::Status status{ false, "Error: Failed to close " + file_name};
        File::WriteRet ret{ status };
        return ret;
    }

    File::Status status{ true, "Ok"};
    File::WriteRet ret{ status };
    return ret;
}

#endif