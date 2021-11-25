cmake_minimum_required(VERSION 2.8)
project(EX1)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")
set(SRC_LIST ex1.cpp)

add_executable(ex1 ${SRC_LIST})
