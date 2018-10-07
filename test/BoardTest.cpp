/**
 * Project: Chess Tests
 * Name: BoardTest.cpp
 * Purpose: Testing all Board`s methods
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#include <Board.h>
#include <Move.h>
#include <RegularMove.h>
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
 * Tests if "move" method can move pawn to empty field
 */
TEST_F(BoardTest, shouldMoveFromOneFieldToOtherEmptyField)
{
    Chessman* whitePawn = new Pawn(true, board);
    whitePawn->set(1,1);
    board->move(new RegularMove(1,1,2,2));
    ASSERT_EQ(board->getChessman(2,2), whitePawn);
    ASSERT_EQ(board->getChessman(1,1), nullptr);
}

/**
 * Tests if "undo" method can undo move
 */
TEST_F(BoardTest, shouldUndoMoves)
{
    Chessman* whitePawn = new Pawn(true, board);
    whitePawn->set(1,1);
    board->move(new RegularMove(1,1,2,2));
    ASSERT_EQ(board->getChessman(2,2), whitePawn);
    ASSERT_EQ(board->getChessman(1,1), nullptr);
    board->undo();
    ASSERT_EQ(board->getChessman(1,1), whitePawn);
    ASSERT_EQ(board->getChessman(2,2), nullptr);
}

/**
 * Tests if "redo" method can redo move
 */
TEST_F(BoardTest, shouldRedoMoves)
{
    Chessman* whitePawn = new Pawn(true, board);
    whitePawn->set(1,1);
    board->move(new RegularMove(1,1,2,2));
    ASSERT_EQ(board->getChessman(2,2), whitePawn);
    ASSERT_EQ(board->getChessman(1,1), nullptr);
    board->undo();
    ASSERT_EQ(board->getChessman(1,1), whitePawn);
    ASSERT_EQ(board->getChessman(2,2), nullptr);
    board->redo();
    ASSERT_EQ(board->getChessman(2,2), whitePawn);
    ASSERT_EQ(board->getChessman(1,1), nullptr);
}

/**
 * Tests if "lastMove" method returns last move
 */
TEST_F(BoardTest, shouldReturnLastMove)
{
    Chessman* whiteChessman = new Pawn(true, board);
    whiteChessman->set(4,1);
    Move* move = new RegularMove(4,1,4,3);
    ASSERT_EQ(board->getLastMove(), nullptr);
    board->move(move);
    ASSERT_EQ(board->getLastMove(), move);

    Move* nextMove = new RegularMove(4,3,4,4);
    board->move(nextMove);
    ASSERT_EQ(board->getLastMove(), nextMove);
    board->undo();
    ASSERT_EQ(board->getLastMove(), move);
    board->redo();
    ASSERT_EQ(board->getLastMove(), nextMove);

}