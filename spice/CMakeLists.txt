cmake_minimum_required(VERSION 3.17)
project(spice)

set(CMAKE_CXX_STANDARD 14)

add_executable(spice main.cpp Spice.cpp Spice.h Component.h Components/Resistor.cpp Components/Resistor.h)