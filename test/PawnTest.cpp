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
    ASSERT_EQ(possibleMoves.size(), 1);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,3)), possibleMoves.end());

    board->setChessman(0, 5, blackPawn);
    possibleMoves = blackPawn->getPossibleMoves(board, 0, 5);
    ASSERT_EQ(possibleMoves.size(), 1);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,4)), possibleMoves.end());
}

/**
 * Checks if Pawn can not move forward if field in front of its is taken
 */
TEST_F(PawnTest, shouldNotMoveForwardIfFieldInFrontIsNotEmpty)
{
    board->setChessman(0, 1, whitePawn);
    board->setChessman(0, 2, blackPawn);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 1);
    ASSERT_TRUE(possibleMoves.empty());
}

/**
 * Checks if Pawn staying on starting line can move forward by two fields if those are empty
 */
TEST_F(PawnTest, shouldCanMoveForwardByTwoFieldsIfThoseAreEmptyOnStart)
{
    board->setChessman(0, 1, whitePawn);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 1);
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,2)), possibleMoves.end());
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,3)), possibleMoves.end());


    board->setChessman(0, 6, blackPawn);
    possibleMoves = blackPawn->getPossibleMoves(board, 0, 6);
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,5)), possibleMoves.end());
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,4)), possibleMoves.end());
}

/**
 * Checks if Pawn can attack diagonally
 */
TEST_F(PawnTest, shouldCanMoveDiagonallyIfThereIsEnemyChessman)
{
    board->setChessman(0, 2, whitePawn);
    board->setChessman(1, 3, blackPawn);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 2);

    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,3)), possibleMoves.end());
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(1,3)), possibleMoves.end());

    possibleMoves = blackPawn->getPossibleMoves(board, 1, 3);
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(1,2)), possibleMoves.end());
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,2)), possibleMoves.end());

}

/**
 * Checks if Black Pawn can attack en passant
 */
TEST_F(PawnTest, shouldBlackPawnCanDoEnPassant)
{
    board->setChessman(0, 1, whitePawn);
    board->setChessman(1, 3, blackPawn);
    board->move(0, 1, 0, 3);
    std::vector<std::tuple<int, int>> possibleMoves = blackPawn->getPossibleMoves(board, 1, 3);
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(1,2)), possibleMoves.end());
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,2)), possibleMoves.end());

}

/**
 * Checks if White Pawn can attack en passant
 */
TEST_F(PawnTest, shouldWhitePawnCanDoEnPassant)
{
    board->setChessman(0, 4, whitePawn);
    board->setChessman(1, 6, blackPawn);
    board->move(1, 6, 1, 4);
    std::vector<std::tuple<int, int>> possibleMoves = whitePawn->getPossibleMoves(board, 0, 4);
    ASSERT_EQ(possibleMoves.size(), 2);
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(0,5)), possibleMoves.end());
    ASSERT_NE(std::find(possibleMoves.begin(), possibleMoves.end(), std::make_tuple(1,5)), possibleMoves.end());

}