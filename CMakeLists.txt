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

#FOR GOOGLE TESTS
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
#GOOGLE TESTS END

#FOR GUI

include_directories(src)
file(GLOB SOURCES "src/*.cpp")

include_directories(interface)
#set(CMAKE_PREFIX_PATH "/Users/nicksemin/Qt/5.15.2")
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set_property(SOURCE ${SOURCES} PROPERTY SKIP_AUTOUIC ON)
include_directories(src/include)
add_executable(interface
        interface/simulationview.ui
        interface/simulationview.cpp
        interface/simulationview.h
        interface/progressbar.ui
        interface/progressbar.cpp
        interface/progressbar.h
        ${SOURCES}
        interface/CustomView.cpp interface/CustomView.h interface/startwindow.cpp interface/startwindow.h interface/startwindow.ui)



target_link_libraries(interface Qt5::Widgets Qt5::Core)
#GUI ENDS
file(GLOB SOURCES "src/*.cpp")

add_executable(simulation ${SOURCES})