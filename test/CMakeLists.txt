project(Tests)

add_subdirectory(lib/googletest-master)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
ADD_LIBRARY(src
        ../src/Board.cpp
        ../include/Board.h
        ../src/Chessman.cpp
        ../include/Chessman.h
        ../src/Queen.cpp
        ../include/Queen.h
        ../src/King.cpp
        ../include/King.h
        ../src/Rook.cpp
        ../include/Rook.h
        ../src/Bishop.cpp
        ../include/Bishop.h
        ../src/Knight.cpp
        ../include/Knight.h
        ../src/Pawn.cpp
        ../include/Pawn.h
        ../src/Rules.cpp
        ../include/Rules.h)

add_executable(Tests BoardTest.cpp ChessmanTest.cpp RulesTest.cpp)
target_link_libraries(Tests gtest gtest_main)
target_link_libraries(Tests src)
