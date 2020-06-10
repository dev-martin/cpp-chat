#include <iostream>
#include "chat.h"

#define SERVER_PORT 8081

int main()
{
    std::string server_ip = "127.0.0.1";
    Client client = Client(SERVER_PORT,server_ip);

    client.setup();
    
    client.connection();
    
}