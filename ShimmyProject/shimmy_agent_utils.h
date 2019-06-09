//
// Created by maaz on 6/5/19.
//

#ifndef SHIMMYPROJECT_SHIMMY_AGENT_UTILS_H
#define SHIMMYPROJECT_SHIMMY_AGENT_UTILS_H

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

namespace shimmy_agent{
    class utils {

    public:

        int get_channel();

    private:

        struct sockaddr_in master_addr;

        int create_shm();

        int reg_pub();

    };
}

#endif //SHIMMYPROJECT_SHIMMY_AGENT_UTILS_H
