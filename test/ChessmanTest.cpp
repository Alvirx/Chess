/**
 * Project: Chess Tests
 * Name: ChessmanTest.cpp
 * Purpose: Testing all Chessman`s methods
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/


#include "gtest/gtest.h"
#include "Queen.h"
#include "Board.h"

/**
 * Fixture that creates, stores and deletes tested instance of Chessman
 */
class ChessmanTest : public ::testing::Test {
public:
    /**
     * Creates white queen chessman
     */
    ChessmanTest()
    {
        board = new Board();
        queen = new Queen(true, board);
    }
    /**
     * deletes chessman
     */
    ~ChessmanTest() override = default;

    Queen* queen;
    Board* board;
};

/**
 * Checks if Chessman can be set properly on board
 */
TEST_F(ChessmanTest, shouldProperlySetChessmanOnBoard)
{
    queen->set(0, 2);
    ASSERT_EQ(queen->getX(), 0);
    ASSERT_EQ(queen->getY(), 2);
    ASSERT_EQ(board->getChessman(0, 2), queen);
}

/**
 * Checks if Chessman can be moved on board on empty fields with set method
 */
TEST_F(ChessmanTest, shouldMoveToOtherEmptyField)
{
    queen->set(0, 2);
    ASSERT_EQ(queen->getX(), 0);
    ASSERT_EQ(queen->getY(), 2);
    ASSERT_EQ(board->getChessman(0, 2), queen);

    queen->set(1, 2);
    ASSERT_EQ(queen->getX(), 1);
    ASSERT_EQ(queen->getY(), 2);
    ASSERT_EQ(board->getChessman(1, 2), queen);
    ASSERT_EQ(board->getChessman(0, 2), nullptr); //last position should be now empty
}


/**
 * Checks if Chessman removed from game can not be set anywhere
 */
TEST_F(ChessmanTest, shouldNotDoAnythingIfBoardPointerInsideIsEmpty)
{
    queen->set(0, 2);
    ASSERT_EQ(queen->getX(), 0);
    ASSERT_EQ(queen->getY(), 2);
    ASSERT_EQ(board->getChessman(0, 2), queen);
    queen->remove();

    ASSERT_EQ(queen->getX(), -1); //these coordinates do not exists on board
    ASSERT_EQ(queen->getY(), -1); //these coordinates do not exists on board
    ASSERT_EQ(board->getChessman(0, 2), nullptr);
}
