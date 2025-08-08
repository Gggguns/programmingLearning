cmake_minimum_required(VERSION 3.10)

project(environmental_construction)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES ./src/*.cc)

include_directories(./src)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
)