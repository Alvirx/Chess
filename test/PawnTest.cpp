/**
 * Project: Chess
 * Name: PawnTest.cpp
 * Purpose: Testing Pawn`s getPossibleMoves method
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 09.09.2018
*/
#include <Pawn.h>
#include <Board.h>
#include "gtest/gtest.h"
#include "RegularMove.h"

/**
 * Fixture that creates, stores and deletes tested instance of Chessman
 */
class PawnTest : public ::testing::Test {
public:
    /**
     * Creates white queen chessman
     */
    PawnTest()
    {
        board = new Board();
        whitePawn   = new Pawn(true, board);
        blackPawn   = new Pawn(false, board);
    }

    /**
     * deletes chessman
     */
    ~PawnTest() override
    {
        delete(whitePawn);
        delete(blackPawn);
        delete(board);
    }

    Chessman* whitePawn;
    Chessman* blackPawn;
    Board* board;
};


/**
 * Checks if Pawn can move forward by one field if field in front of its is empty
 */
TEST_F(PawnTest, shouldMoveForwardByOneFieldIfThatsEmpty)
{
    whitePawn->set(0,2);
    std::vector<Move*> possibleMoves = whitePawn->getPossibleMoves();

    ASSERT_EQ(possibleMoves.size(), 1);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0, 2, 0, 3)), possibleMoves.end());

    blackPawn->set(0,5);
    possibleMoves = blackPawn->getPossibleMoves();
    ASSERT_EQ(possibleMoves.size(), 1);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,5,0,4)), possibleMoves.end());
}

/**
 * Checks if Pawn can not move forward if field in front of its is taken
 */
TEST_F(PawnTest, shouldNotMoveForwardIfFieldInFrontIsNotEmpty)
{
    whitePawn->set(0,1);
    blackPawn->set(0,2);
    std::vector<Move*> possibleMoves = whitePawn->getPossibleMoves();
    ASSERT_TRUE(possibleMoves.empty());
}

/**
 * Checks if Pawn staying on starting line can move forward by two fields if those are empty
 */
TEST_F(PawnTest, shouldCanMoveForwardByTwoFieldsIfThoseAreEmptyOnStart)
{
    whitePawn->set(0,1);
    std::vector<Move*> possibleMoves = whitePawn->getPossibleMoves();
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,1,0,2)), possibleMoves.end());
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,1,0,3)), possibleMoves.end());

    blackPawn->set(0, 6);
    possibleMoves = blackPawn->getPossibleMoves();
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,6,0,5)), possibleMoves.end());
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,6,0,4)), possibleMoves.end());
}

/**
 * Checks if Pawn can attack diagonally
 */
TEST_F(PawnTest, shouldCanMoveDiagonallyIfThereIsEnemyChessman)
{
    whitePawn->set(0,2);
    blackPawn->set(1,3);
    std::vector<Move*> possibleMoves = whitePawn->getPossibleMoves();

    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,2,0,3)), possibleMoves.end());
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,2,1,3)), possibleMoves.end());

    possibleMoves = blackPawn->getPossibleMoves();
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(1,3,1,2)), possibleMoves.end());
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(1,3,0,2)), possibleMoves.end());

}

/**
 * Checks if Black Pawn can attack en passant
 */
TEST_F(PawnTest, shouldBlackPawnCanDoEnPassant)
{
    whitePawn->set(0,1);
    blackPawn->set(1,3);
    board->move(new RegularMove(0,1,0,3));
    std::vector<Move*> possibleMoves = blackPawn->getPossibleMoves();
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(1,3,1,2)), possibleMoves.end());
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(1,3,0,2)), possibleMoves.end());
}

/**
 * Checks if White Pawn can attack en passant
 */
TEST_F(PawnTest, shouldWhitePawnCanDoEnPassant)
{
    whitePawn->set(0,4);
    blackPawn->set(1,6);
    board->move(new RegularMove(1,6,1,4));
    std::vector<Move*> possibleMoves = whitePawn->getPossibleMoves();
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,4,0,5)), possibleMoves.end());
    ASSERT_NE(std::find_if(possibleMoves.begin(), possibleMoves.end(), RegularMove(0,4,1,5)), possibleMoves.end());
}