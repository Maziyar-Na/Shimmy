//
// Created by maaz on 6/5/19.
//

#ifndef SHIMMYPROJECT_SHIMMY_MASTER_PUBLISHER_H
#define SHIMMYPROJECT_SHIMMY_MASTER_PUBLISHER_H
#define __MAX_PUB_NO__ 65536

#include <vector>
#include <iostream>
#include "shimmy_agent.h"

namespace shimmy_master{

    typedef struct pub{

        pub(int _id, int _shm_id, std::string _host_id) : id(_id), shm_id(_shm_id), host_id(_host_id){}
        pub(std::string _host_id) : host_id(_host_id){}

        int id;
        int shm_id;
        std::string host_id;

    }pub_t;

    class pub_utils {

    public:

        int reg_pub(pub_t new_pub);

        int unreg_pub(int id);

    private:

        std::vector< pub_t > pub_store;

        std::vector< shimmy_agent::shimmy_agent_t> agents;

        int gen_new_id();
    };

}

#endif //SHIMMYPROJECT_SHIMMY_MASTER_PUBLISHER_H
