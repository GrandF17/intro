#ifndef INTRO_UTILS_REQUEST_CPP_INCLUDED
#define INTRO_UTILS_REQUEST_CPP_INCLUDED

#include <mutex>

// For thread-safe logging
mutex log_mutex;  

inline void handle_client(int client_socket) {
    Logger log_file(string("./data/log.txt"), false);
    char buffer[1024];
    
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            return;
        }

        lock_guard<mutex> guard(log_mutex);
        string msg(buffer, buffer + bytes_received);
        log_file.log(msg);
    }
}

#endif