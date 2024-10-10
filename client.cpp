#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "./utils/time.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <client_name> <server_port> <period_in_seconds>" << endl;
        return 1;
    }

    string client_name = argv[1];
    int server_port = stoi(argv[2]);
    int period = stoi(argv[3]);
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if (client_socket < 0) {
        cerr << "Error creating socket." << endl;
        return 1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(client_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        cerr << "Connection failed." << endl;
        return 1;
    }

    while (true) {
        string message = timestamp() + client_name;
        send(client_socket, message.c_str(), message.size(), 0);
        this_thread::sleep_for(chrono::seconds(period));
    }

    close(client_socket);
    return 0;
}
