cmake_minimum_required(VERSION 3.10)
project(assertions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(assertions main.cpp)
target_link_libraries(assertions PRIVATE pulley)
