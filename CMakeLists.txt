cmake_minimum_required(VERSION 3.5)
project(TestEngines)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC)
set(CMAKE_AUTORCC)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)

add_executable(TestEngines main.cpp core.cpp engine.cpp jsonprinter.cpp)

# linking
target_link_libraries(TestEngines Qt5::Core)

