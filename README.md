## Server App:
### Compile:
`g++ -o server server.cpp ./libs/logger.cpp ./libs/file.cpp -pthread`

### Run:
`./server 3000`

## Client App:
### Compile:
`g++ client.cpp -o client`

### Run:
`./client Name1 3000 1`