#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

#include "./libs/file.h"
#include "./libs/logger.h"
#include "./utils/request.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <port>" << endl;
        return 1;
    }

    int server_port = stoi(argv[1]);
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (server_socket < 0) {
        cerr << "Error creating socket." << endl;
        return 1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "Binding failed." << endl;
        return 1;
    }

    listen(server_socket, 5);
    cout << "Server listening on port " << server_port << endl;

    while (true) {
        int client_socket = accept(server_socket, nullptr, nullptr);
        // for each client a separate thread
        if (client_socket >= 0) thread(handle_client, client_socket).detach();
    }

    close(server_socket);
    return 0;
}
