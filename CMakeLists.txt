cmake_minimum_required(VERSION 3.5)
project(TestEngines)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED)

add_executable(TestEngines main.cpp core.cpp engine.cpp jsonprinter.cpp jsonprinter.h)

# linking
target_link_libraries(TestEngines Qt5::Core)

