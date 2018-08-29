/**
 * Project: Chess Tests
 * Name: BoardTest.cpp
 * Purpose: Testing all Board`s methods
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/
#include <Board.h>
#include "gtest/gtest.h"
#include "Chessman.h"
/**
 * Fixture that creates, stores and deletes tested instance of Board
 */
class BoardTest : public ::testing::Test {
public:
    /**
     * Creates basic Board for chess game
     */
    BoardTest()
    {
        board = new Board();
    }

    /**
     * deletes board
     */
    ~BoardTest() override
    {
        delete(board);
    }
    /**
     * board getter
     * @return board which is tested
     */
    Board *getBoard() const {
        return board;
    }

    Board* board;
};

/**
 * Tests if on the "A1" field on the beginning is white rook Chessman
 */
TEST_F(BoardTest, shouldHaveChessmansInRightPostionOnStart)
{
    //Chessman* chessman = board->getChessman("A1");
    //ASSERT_EQ(chessman->getType(), ChessmanType(rook));
    //ASSERT_EQ(chessman->isWhite(), true);
}