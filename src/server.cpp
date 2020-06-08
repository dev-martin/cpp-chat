#include <iostream>
#include <string.h>
#include <chat.h>

#define MAX_QUEUE_SIZE 20
#define PORT 8080

int main()
{
    // Setup server's socket for incoming connections
    Server my_server = Server(PORT, MAX_QUEUE_SIZE); 
    my_server.setup();
    
    // Wait for connections to come in continously
    while(true){
        // Accept connection from client and launch thread to handle this client
        

        // Action that triggers server to shut down
    }

}