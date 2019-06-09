//
// Created by maaz on 6/7/19.
//

#include "master_client.h"

int shimmy_master::client::send_req() {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "create_shm";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "\n Socket creation error \n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(__AGENTPORT__);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        std::cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Create shared memory command sent\n");
    valread = read( sock , buffer, __BUFFSIZE__);
    printf("%s\n",buffer );
    return 0;
}