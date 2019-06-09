//
// Created by maaz on 6/6/19.
//

#ifndef SHIMMYPROJECT_MASTER_SERVER_H
#define SHIMMYPROJECT_MASTER_SERVER_H
#define __SHM_PORT__ 8080
#define  __REG_SUCCEEDED__ 0
#define __REG_FAILED__ -1
#define __BUFFSIZE__ 64
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include "shimmy_master_publisher.h"

namespace shimmy_master {

    class server {

    public:

        server();

        int handle_request(char* req);

        void start();

    private:
        struct sockaddr_in address;

        int serverfd;
        //for server socket options
        int opt;

        int addrlen;

        char buff[__BUFFSIZE__];

        shimmy_master::pub_utils* publisher_utils;
    };
}
#endif //SHIMMYPROJECT_MASTER_SERVER_H
