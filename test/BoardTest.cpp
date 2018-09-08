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
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"

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

    Board* board;
};

/**
 * Tests if "getChessman" returns Chessman from chosen field, and board is empty on the beginning
 */
TEST_F(BoardTest, shouldGetChessmanProperly)
{
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            Chessman* chessman = board->getChessman(i, j);
            ASSERT_EQ(chessman, nullptr);
        }

}

/**
 * Tests if "setChessman" sets Chessman on chosen field
 */
TEST_F(BoardTest, shouldSetChessmanProperly)
{
    board->setChessman(0, 0, new Queen(true));
    Chessman* chessman = board->getChessman(0, 0);
    ASSERT_NE(dynamic_cast<Queen*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);
}


/**
 * Tests if "move" method can move pawn to empty field
 */
TEST_F(BoardTest, shouldMoveFromOneFieldToOtherEmptyField)
{
    Chessman* chessman = new Pawn(true);
    board->setChessman(4, 1, chessman);
    ASSERT_NE(dynamic_cast<Pawn*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);
    board->move(4, 1, 4, 3);
    ASSERT_EQ(board->getChessman(4, 1), nullptr);
    ASSERT_EQ(board->getChessman(4, 3), chessman);
}


/**
 * Tests if "move" method returns taken Chessman
 */
TEST_F(BoardTest, shouldReturnTakenChessman)
{
    Chessman* blackChessman = new Pawn(false);
    Chessman* whiteChessman = new Pawn(true);
    board->setChessman(3, 6, blackChessman);
    board->setChessman(4, 1, whiteChessman);

    board->move(4, 1, 4, 3);
    board->move(3, 6, 3, 4);
    Chessman* takenChessman = board->move(4, 3, 3, 4);
    ASSERT_EQ(takenChessman, blackChessman);
    ASSERT_EQ(board->getChessman(3, 4), whiteChessman);
    ASSERT_EQ(board->getChessman(4, 1), nullptr);
    ASSERT_EQ(board->getChessman(4, 3), nullptr);
    ASSERT_EQ(board->getChessman(3, 6), nullptr);
}

/**
 * Tests if "move" method not change anything if "from" field is empty
 */
TEST_F(BoardTest, shouldNotMoveAnythingIfFromFieldIsEmpty)
{
    Chessman* blackChessman = new Pawn(false);
    Chessman* whiteChessman = new Pawn(true);
    board->setChessman(3, 6, blackChessman);
    board->setChessman(4, 1, whiteChessman);


    board->move(4, 1, 4, 3);
    board->move(3, 6, 3, 4);
    Chessman* takenChessman = board->move(3, 3, 3, 4);
    ASSERT_EQ(takenChessman, nullptr);
    ASSERT_EQ(board->getChessman(3, 4), blackChessman);
    ASSERT_EQ(board->getChessman(4, 3), whiteChessman);
    ASSERT_EQ(board->getChessman(4, 1), nullptr);
    ASSERT_EQ(board->getChessman(4, 1), nullptr);
    ASSERT_EQ(board->getChessman(3, 3), nullptr);
}
