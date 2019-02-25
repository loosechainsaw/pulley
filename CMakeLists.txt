cmake_minimum_required(VERSION 3.10)
project(pulley)

add_subdirectory(assertions)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS
        include/pulley/utitlities/null_type.hpp
        include/pulley/algorithms/take.hpp
        include/pulley/algorithms/transform.hpp
        include/pulley/algorithms/front.hpp
        include/pulley/algorithms/back.hpp
        include/pulley/algorithms/types/front.hpp
        include/pulley/algorithms/types/transform.hpp
        include/pulley/algorithms/types/back.hpp
        include/pulley/algorithms/tail.hpp
        include/pulley/algorithms/remove.hpp
        include/pulley/algorithms/types/tail_empty.hpp
        include/pulley/algorithms/types/tail_size.hpp
        include/pulley/algorithms/skip.hpp
        include/pulley/algorithms/count_if.hpp
        include/pulley/algorithms/find.hpp
        include/pulley/algorithms/for_each.hpp
        include/pulley/algorithms/adjacent_elements_for_each.hpp
        include/pulley/algorithms/adjacent_elements_for_each_if.hpp
        include/pulley/algorithms/any_pairs.hpp
        include/pulley/algorithms/all_of.hpp)

add_library(pulley INTERFACE )
target_include_directories(pulley INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

