cmake_minimum_required(VERSION 3.8)
project(Algorithms)
set(CMAKE_BUILD_TYPE Debug)

add_executable(Algorithms Algorithms.cpp HashTable.h HashTable.cpp)
set_property(TARGET Algorithms PROPERTY CXX_STANDARD 11)