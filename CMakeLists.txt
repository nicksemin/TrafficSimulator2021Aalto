cmake_minimum_required(VERSION 3.10)
project(traffic_simulator)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Compiler options necessary for debug (Alexey)
add_compile_options(-g --pedantic-errors)
include_directories(tests)

enable_testing()

include_directories(src)

add_executable(
        person_test
        tests/PersonTest.cpp
)
target_link_libraries(
        person_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(person_test)

file(GLOB SOURCES "src/*.cpp")

add_executable(simulation ${SOURCES})
