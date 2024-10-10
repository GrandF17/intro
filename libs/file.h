#ifndef INTRO_LIBS_FILE_H_INCLUDED
#define INTRO_LIBS_FILE_H_INCLUDED

#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

class File {
    public:
     struct Status {
          bool success;
          string error;
     };

     struct ReadRet {
          vector<uint8_t> data;
          Status status;
     };

     struct WriteRet {
          Status status;
     };

     ////////////////////////////////////

     ReadRet read(string file_name);

     /**
      * both "save" functions append 
      * info to the following file
      */
     WriteRet save(/**vector<uint8_t> */string const& data, string file_name);

     /**
      * serves to delete all data 
      * from the following file
      */
     WriteRet clean(string file_name);
};

#endif