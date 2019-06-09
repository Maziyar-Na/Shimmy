//
// Created by maaz on 6/7/19.
//

#ifndef SHIMMYPROJECT_SHIMMY_AGENT_H
#define SHIMMYPROJECT_SHIMMY_AGENT_H


#include <string>

namespace shimmy_agent {

    typedef struct shagent{

        std::string hostid;

        std::string ip;

        int port;

    }shimmy_agent_t;
}

#endif //SHIMMYPROJECT_SHIMMY_AGENT_H
