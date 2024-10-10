### Compile
`g++ -o server server.cpp ./libs/logger.cpp ./libs/file.cpp -pthread`
`g++ client.cpp -o client`

### Run server
`./server 3000`

### Run client
`./client Name1 3000 1`