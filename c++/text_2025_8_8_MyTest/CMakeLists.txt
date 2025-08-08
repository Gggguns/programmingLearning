cmake_minimum_required(VERSION 3.10)

project(MyTest LANGUAGES CXX)
message(STATUS "Configuring MyTest project")

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES ./src/*.cpp ./src/*.cc)

set(INCLUDE "./src")
include_directories(${INCLUDE})

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)
