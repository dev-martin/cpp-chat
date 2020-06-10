#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

class Server
{
    int sock, port_num, max_queue_size;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

public:
    Server(int port_num, int max_queue_size);
    void setup();
    int accept_connection();
};

class Client
{
    int sock, server_port_number;
    std::string server_ip;
    struct sockaddr_in serv_addr;

public:
    Client(int port_number, std::string server_ip);
    void setup();
    void connection();
};