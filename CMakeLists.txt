cmake_minimum_required(VERSION 3.2)

project(demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAG "${CMAKE_CXX_FLAGS} -g -Wall")
set(CMAKE_BUILD_TYPE Debug)

include_directories(includes)

file(GLOB SRC ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} main.cpp ${SRC})