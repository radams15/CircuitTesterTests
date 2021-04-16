cmake_minimum_required(VERSION 3.17)
project(spice)

set(CMAKE_CXX_STANDARD 14)

set(EIGEN3_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/modules/eigen-3.3.9)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Eigen3 3.3.9 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(spice main.cpp Component.h Components/Resistor.cpp Components/Resistor.h Sim.cpp Sim.h NodeHashTable.cpp NodeHashTable.h Component.cpp Components.h)