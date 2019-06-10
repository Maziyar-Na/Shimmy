#include <iostream>
#include "master_server.h"
#include "agent_server.h"

int main() {
    shimmy_master::server *shm_server = new shimmy_master::server();
    //shimmy_agent::server* sha_server = new shimmy_agent::server();

    shm_server->start();
    //sha_server->start();

    return 0;
}