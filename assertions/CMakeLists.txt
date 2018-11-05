cmake_minimum_required(VERSION 3.10)
project(assertions)

add_executable(assertions main.cpp)
target_link_libraries(assertions PRIVATE pulley)