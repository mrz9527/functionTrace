cmake_minimum_required(VERSION 3.5.1)
project(functionTrace)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(Framework)

# -export-dynamic选项，用来支持dladdr将函数符号表转换为函数名，如果没有该选项，dladdr转化得到的函数名为null
# 或者不用dladdr，而直接通过addr2line命令行的方式也可以。
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -finstrument-functions -export-dynamic")

add_executable(functionTraceDemo main.cpp)
target_link_libraries(functionTraceDemo functionTrace)