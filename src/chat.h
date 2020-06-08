#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

// Class for server
class Server {
    int server_socket,port_num,max_queue_size;
    int opt = 1;
    struct sockaddr_in server_address;
    int addrlen = sizeof(server_address);
    
    public:
        Server(int port_num,int max_queue_size){
            this->port_num = port_num;
            this->max_queue_size = max_queue_size;
        }

        void setup(){
            // Creating socket file descriptor
            if ((this->server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
            {
                perror("Server socket failed");
                exit(EXIT_FAILURE);
            }
            // Forcefully attaching socket to the port 8080
            if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &this->opt, sizeof(opt)))
            {
                perror("setsockopt");
                exit(EXIT_FAILURE);
            }
            this->server_address.sin_family = AF_INET;
            this->server_address.sin_addr.s_addr = INADDR_ANY;
            this->server_address.sin_port = htons(this->port_num);

            // Forcefully attaching socket to the port 8080
            if (bind(this->server_socket, (struct sockaddr *)&this->server_address, sizeof(this->server_address)) < 0)
            {
                perror("bind failed");
                exit(EXIT_FAILURE);
            }
            if (listen(this->server_socket, this->max_queue_size) < 0)
            {
                perror("listen");
                exit(EXIT_FAILURE);
            }
        }

        int accept_connection(){
            int client_socket;
            if ((client_socket = accept(this->server_socket, (struct sockaddr *)&this->server_address,(socklen_t *)&this->addrlen)) < 0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            else
                return client_socket;
        }

};
