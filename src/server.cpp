#include <iostream>
#include "chat.h"

#define MAX_QUEUE_SIZE 20
#define PORT 8081

int main()
{
    
    // * Setup server's socket for incoming connections
    Server my_server = Server(PORT, MAX_QUEUE_SIZE); 
    my_server.setup();

    // Wait for connections to come in continously
    while(true){
        // Accept connection from client 
        int client_socket = my_server.accept_connection();
        
        // TODO: Launch thread to handle client

        // TODO: Action that triggers server to shut down
    }

}