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
        whitePawn   = new Pawn(true);
        blackPawn   = new Pawn(false);
        board = new Board();
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
    board->setChessman(0, 2, whitePawn);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 2);
    ASSERT_EQ(possibleMoves.empty(), false);
    std::tuple<int,int> move = possibleMoves[0];
    ASSERT_EQ(std::get<0>(move), 0);
    ASSERT_EQ(std::get<1>(move), 3);

    board->setChessman(0, 5, blackPawn);
    possibleMoves = blackPawn->getPossibleMoves(board, 0, 5);
    ASSERT_EQ(possibleMoves.empty(), false);
    move = possibleMoves[0];
    ASSERT_EQ(std::get<0>(move), 0);
    ASSERT_EQ(std::get<1>(move), 4);
}

/**
 * Checks if Pawn can not move forward if field in front of its is taken
 */
TEST_F(PawnTest, shouldNotMoveForwardIfFieldInFrontIsNotEmpty)
{
    board->setChessman(0, 1, whitePawn);
    board->setChessman(0, 2, blackPawn);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 1);
    ASSERT_EQ(possibleMoves.empty(), true);
}

/**
 * Checks if Pawn staying on starting line can move forward by two fields if those are empty
 */
TEST_F(PawnTest, shouldCanMoveForwardByTwoFieldsIfThoseAreEmptyOnStart)
{
    board->setChessman(0, 1, whitePawn);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 1);
    ASSERT_EQ(possibleMoves.size()>1, true);
    std::tuple<int,int> move = possibleMoves[0];
    ASSERT_EQ(std::get<0>(move), 0);
    ASSERT_EQ(std::get<1>(move), 2);
    move = possibleMoves[1];
    ASSERT_EQ(std::get<0>(move), 0);
    ASSERT_EQ(std::get<1>(move), 3);


    board->setChessman(0, 6, blackPawn);
    possibleMoves = blackPawn->getPossibleMoves(board, 0, 6);
    ASSERT_EQ(possibleMoves.size()>1, true);
    move = possibleMoves[0];
    ASSERT_EQ(std::get<0>(move), 0);
    ASSERT_EQ(std::get<1>(move), 5);
    move = possibleMoves[1];
    ASSERT_EQ(std::get<0>(move), 0);
    ASSERT_EQ(std::get<1>(move), 4);
}

/**
 * Checks if Pawn can attack diagonally
 */
TEST_F(PawnTest, shouldCanMoveDiagonallyIfThereIsEnemyChessman)
{
    //TODO write this test
}