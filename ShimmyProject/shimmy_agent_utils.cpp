//
// Created by maaz on 6/7/19.
//

#include "shimmy_agent_utils.h"


int shimmy_agent::utils::get_channel() {
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);

    return shmid;
}