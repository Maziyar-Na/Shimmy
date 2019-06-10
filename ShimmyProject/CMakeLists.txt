cmake_minimum_required(VERSION 3.13)
project(ShimmyProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(ShimmyProject main.cpp shimmy_agent_utils.h shimmy_master_publisher.h shimmy_master_publisher.cpp master_server.h master_server.cpp agent_server.h agent_server.cpp shimmy_agent_utils.cpp shimmy_agent.h master_client.h master_client.cpp)
add_executable(main main.cpp)