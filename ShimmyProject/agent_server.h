//
// Created by maaz on 6/7/19.
//

#ifndef SHIMMYPROJECT_AGENT_SERVER_H
#define SHIMMYPROJECT_AGENT_SERVER_H
#define __BUFFSIZE__ 64
#define __SHA_PORT__ 9090
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include "shimmy_master_publisher.h"
#include "shimmy_agent_utils.h"

namespace shimmy_agent {

    class server {

    public:

        server();

        void start();

    private:
        struct sockaddr_in address;

        int serverfd;
        //for server socket options
        int opt;

        int addrlen;

        char buff[__BUFFSIZE__];

        shimmy_agent::utils* utils;

        int handle_request(char* req);
    };
}

#endif //SHIMMYPROJECT_AGENT_SERVER_H
