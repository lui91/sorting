cmake_minimum_required(VERSION 3.8)
project(sorting)
#set(CMAKE_BUILD_TYPE Debug)

add_executable(sorting Algorithms.cpp HashTable.h HashTable.cpp binaryoperations.cpp linked_list.cpp)
set_property(TARGET sorting PROPERTY CXX_STANDARD 11)