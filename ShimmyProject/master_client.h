//
// Created by maaz on 6/7/19.
//

#ifndef SHIMMYPROJECT_MASTER_CLIENT_H
#define SHIMMYPROJECT_MASTER_CLIENT_H

#define __AGENTPORT__ 9090
#define __BUFFSIZE__ 64
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>

namespace shimmy_master{

    class client {
    private:

    public:

        int send_req();
    };
}

#endif //SHIMMYPROJECT_MASTER_CLIENT_H
