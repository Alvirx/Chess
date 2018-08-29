cmake_minimum_required(VERSION 3.12)
project(Chess)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(Chess main.cpp src/Board.cpp include/Board.h src/Chessman.cpp include/Chessman.h)

add_subdirectory(test)