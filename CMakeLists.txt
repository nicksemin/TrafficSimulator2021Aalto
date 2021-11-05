cmake_minimum_required(VERSION 3.10)
project(traffic_simulator)

file(GLOB SOURCES "src/*.cpp")

add_executable(simulation ${SOURCES})