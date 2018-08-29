project(Tests)

add_subdirectory(lib/googletest-master)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
ADD_LIBRARY(src ../src/Board.cpp ../include/Board.h ../src/Chessman.cpp ../include/Chessman.h)

add_executable(Tests BoardTest.cpp ChessmanTest.cpp)
target_link_libraries(Tests gtest gtest_main)
target_link_libraries(Tests src)
