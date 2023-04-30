cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled algorithm/Person/Person.cpp algorithm/Person/Person.h algorithm/min_max_element.cpp)
