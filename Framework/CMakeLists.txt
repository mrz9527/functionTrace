cmake_minimum_required(VERSION 3.5.1)
project(functionTrace)

set(CMAKE_CXX_STANDARD 11)

add_library(functionTrace SHARED function_trace_hook.cpp)

#dl库，用来连接dladdr
target_link_libraries(functionTrace dl)