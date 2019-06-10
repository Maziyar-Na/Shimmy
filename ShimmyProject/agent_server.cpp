//
// Created by maaz on 6/7/19.
//

#include "agent_server.h"

shimmy_agent::server::server() {
    opt = 1;
    addrlen = sizeof(address);
    memset(buff, __BUFFSIZE__, '\0');
    utils = new shimmy_agent::utils();
}

void shimmy_agent::server::start() {
    int new_socket;
    // Creating socket file descriptor
    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("[Error] Shimmy master --> Server socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("[Error] Shimmy master --> setting socket options not completed!");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( __SHA_PORT__ );

    // Forcefully attaching socket to the port 8080
    if (bind(serverfd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("[Error] Shimmy master --> binding server socket encountered an error!");
        exit(EXIT_FAILURE);
    }

    if (listen(serverfd, 5) < 0)
    {
        perror("[Error] Shimmy master --> listening failed!");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(serverfd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen))<0)
    {
        perror("[Error] Shimmy master: error happened while accepting a connection!");
        exit(EXIT_FAILURE);
    }

    int byte_read = read( new_socket , buff, __BUFFSIZE__);
    //printf("%s\n",buff );
    std::cout << "[dbg] Shimmy agent --> I got the request and it is: " << std::string(buff) << std:: endl;
    int response = this->handle_request(buff);
    std::cout << "[dbg] Shimmy agent --> to_string(response): " << response << std:: endl;
    std::string s = std::to_string(response);
    char const *pchar = s.c_str();
    send(new_socket ,  pchar, strlen(pchar) , 0 );
    std:: cout << "[dbg] shimmy agent --> shared memory id is: " << s << std::endl;
}

int shimmy_agent::server::handle_request(char *req) {
    //std::string s(req);

    if (!strcmp(req, "create_shm")){
        std::cout << "[dbg] we got here, trying yo get shared memory channel!" << std::endl;
        return utils->get_channel();
    }
    std::cout << "[dbg] we got here, and achieve nothing!" << std::endl;
    return 0;
}