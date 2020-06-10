#include "chat.h"
// Server implementation
Server::Server(int port_num, int max_queue_size)
{
    this->port_num = port_num;
    this->max_queue_size = max_queue_size;
}

void Server::setup()
{
    // Creating socket file descriptor
    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Server socket failed");
        exit(EXIT_FAILURE);
    }

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(this->port_num);

    // Forcefully attaching socket to the port 8080
    if (bind(this->sock, (struct sockaddr *)&this->address, sizeof(this->address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(this->sock, this->max_queue_size) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

int Server::accept_connection()
{
    int client_socket;
    if ((client_socket = accept(this->sock, (struct sockaddr *)&this->address, (socklen_t *)&this->addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    return client_socket;
}

// Class for the Client
Client::Client(int server_port_number, std::string server_ip){
    // Specify port_number the client connects to
    this->server_port_number = server_port_number;
    this->server_ip = server_ip;
}

void Client::setup(){
    if ((this->sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return;
    }

    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(this->server_port_number);

    // Convert IPv4 and IPv6 addresses from text to binary form
    char *server_ip = (char *)malloc(sizeof(char)*this->server_ip.length());
    std::strcpy(server_ip,this->server_ip.c_str()); 
    
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return;
    }
}
void Client::connection(){
    if (connect(this->sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(1);
    }
}