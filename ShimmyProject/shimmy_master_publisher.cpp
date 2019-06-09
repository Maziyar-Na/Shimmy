//
// Created by maaz on 6/5/19.
//

#include <cstdlib>
#include "shimmy_master_publisher.h"
#include "master_client.h"


int shimmy_master::pub_utils::gen_new_id(){
    int new_id;

    while(true){
        bool flag = false;

        new_id = rand() % __MAX_PUB_NO__ + 1;

        for(int i = 0; i < pub_store.size(); i++){

            if(pub_store[i].id == new_id){
                flag = true;
                break;
            }

        }

        if(!flag)
            break;
    }

    return new_id;
}

int shimmy_master::pub_utils::reg_pub(pub_t new_pub){

    int new_id = gen_new_id();
    new_pub.id = new_id;
    std::cout <<" [dbg] this is the id generated for the publisher container: " << new_id << std::endl;
    shimmy_master::client* c = new client();
    new_pub.shm_id = c->send_req();
    pub_store.push_back(new_pub);

    return new_pub.shm_id;
}

int shimmy_master::pub_utils::unreg_pub(int id){

}