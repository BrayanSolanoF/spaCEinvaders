cmake_minimum_required(VERSION 3.19)
project(untitled9)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)
add_executable(untitled9 main.c socket.c socket.h)