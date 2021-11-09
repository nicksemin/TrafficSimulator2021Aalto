cmake_minimum_required(VERSION 3.10)
project(traffic_simulator)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Compiler options necessary for debug (Alexey)
add_compile_options(-g --pedantic-errors)

file(GLOB SOURCES "src/*.cpp")

add_executable(simulation ${SOURCES})
