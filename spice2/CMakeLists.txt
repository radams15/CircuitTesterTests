cmake_minimum_required(VERSION 3.19)
project(spice2)

set(CMAKE_CXX_STANDARD 14)

set(EIGEN3_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/modules/eigen-3.3.9)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Eigen3 3.3.9 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(spice2 main.cpp Equation.cpp Equation.h MNACircuit.cpp MNACircuit.h Component.cpp Component.h MNAElement.cpp MNAElement.h MNASolution.cpp MNASolution.h)