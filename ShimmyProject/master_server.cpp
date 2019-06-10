//
// Created by maaz on 6/6/19.
//

#include "master_server.h"
#include "shimmy_master_publisher.h"

shimmy_master::server::server() {
    opt = 1;
    addrlen = sizeof(address);
    memset(buff, __BUFFSIZE__, '\0');
    publisher_utils = new shimmy_master::pub_utils();
}


int shimmy_master::server::handle_request(char* req){
    std::string s(req);

    if (s.substr(0,8) == "register"){
        std::string hostid = s.substr( (s.find(",")+1) );
        pub_t new_pub(hostid);
        return publisher_utils->reg_pub(new_pub);
    }
    return -1;

}
void shimmy_master::server::start(){
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
    address.sin_port = htons( __SHM_PORT__ );

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
    int response = handle_request(buff);
    std::string s = std::to_string(response);
    char const *pchar = s.c_str();
    send(new_socket ,  pchar, strlen(pchar) , 0 );
    std:: cout << "Hello message sent\n";

}