#include <Board.h>
#include "gtest/gtest.h"
#include "Chessman.h"

class BoardTest : public ::testing::Test {
public:
    BoardTest()
    {
        board = new Board();
    }

    ~BoardTest() override
    {
        delete(board);
    }
    Board* board;
};

TEST_F(BoardTest, shouldHaveChessmansInRightPostionOnStart)
{
    //Chessman* chessman = board->getChessman("A1");
    //ASSERT_EQ(chessman->getType(), );
}