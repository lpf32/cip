cmake_minimum_required(VERSION 2.6)

project(cip C CXX)

set(C_FLAGS
        -DDEBUG_ETH
        -DDEBUG_ARP
        -DDEBUG_IP)

string(REPLACE ";" " " CMAKE_C_FLAGS "${C_FLAGS}")
message(STATUS "C_FLAGS = " ${CMAKE_C_FLAGS})

include_directories(src)

add_subdirectory(src)