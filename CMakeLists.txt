cmake_minimum_required(VERSION 3.12)
project(Chess)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(Chess main.cpp src/Board.cpp include/Board.h src/Chessman.cpp include/Chessman.h src/Queen.cpp include/Queen.h src/King.cpp include/King.h src/Rook.cpp include/Rook.h src/Bishop.cpp include/Bishop.h src/Knight.cpp include/Knight.h src/Pawn.cpp ../include/Pawn.h src/Rules.cpp include/Rules.h)

add_subdirectory(test)