/**
 * Project: Chess Tests
 * Name: ChessmanTest.cpp
 * Purpose: Testing all Chessman`s methods
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#include <Queen.h>
#include <King.h>
#include <Bishop.h>
#include <Knight.h>
#include <Rook.h>
#include <Pawn.h>
#include "gtest/gtest.h"


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
        whiteQueen  = new Queen(true);
        whitePawn   = new Pawn(true);
        whiteKing   = new King(true);
        blackKnight = new Knight(false);
        blackRook   = new Rook(false);
        blackBishop = new Bishop(false);
    }
    /**
     * deletes chessman
     */
    ~ChessmanTest() override
    {
        delete(whiteQueen);
        delete(whitePawn);
        delete(whiteKing);
        delete(blackBishop);
        delete(blackRook);
        delete(blackKnight);
    }

    Chessman* whiteQueen;
    Chessman* whitePawn;
    Chessman* whiteKing;
    Chessman* blackBishop;
    Chessman* blackRook;
    Chessman* blackKnight;
};


/**
 * Checks if queen chessman works and exists
 */
TEST_F(ChessmanTest, shouldThereBeQueen)
{
    ASSERT_EQ(whiteQueen->isWhite(), true);
    ASSERT_NE(dynamic_cast<Queen*>(whiteQueen), nullptr);
}

/**
 * Checks if king chessman works and exists
 */
TEST_F(ChessmanTest, shouldThereBeKing)
{
    ASSERT_EQ(whiteKing->isWhite(), true);
    ASSERT_NE(dynamic_cast<King*>(whiteKing), nullptr);
}

/**
 * Checks if pawn chessman works and exists
 */
TEST_F(ChessmanTest, shouldThereBePawn)
{
    ASSERT_EQ(whitePawn->isWhite(), true);
    ASSERT_NE(dynamic_cast<Pawn*>(whitePawn), nullptr);
}

/**
 * Checks if bishop chessman works and exists
 */
TEST_F(ChessmanTest, shouldThereBeBishop)
{
    ASSERT_EQ(blackBishop->isWhite(), false);
    ASSERT_NE(dynamic_cast<Bishop*>(blackBishop), nullptr);
}

/**
 * Checks if rook chessman works and exists
 */
TEST_F(ChessmanTest, shouldThereBeRook)
{
    ASSERT_EQ(blackRook->isWhite(), false);
    ASSERT_NE(dynamic_cast<Rook*>(blackRook), nullptr);
}

/**
 * Checks if knight chessman works and exists
 */
TEST_F(ChessmanTest, shouldThereBeKnight)
{
    ASSERT_EQ(blackKnight->isWhite(), false);
    ASSERT_NE(dynamic_cast<Knight*>(blackKnight), nullptr);
}

