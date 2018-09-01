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

    Board* board;
};

/**
 * Tests if on the beginning, on the "A1" field is white rook Chessman
 */
TEST_F(BoardTest, shouldHaveRooksInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("A1");
    ASSERT_EQ(chessman->getType(), ChessmanType(rook));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("H1");
    ASSERT_EQ(chessman->getType(), ChessmanType(rook));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("H8");
    ASSERT_EQ(chessman->getType(), ChessmanType(rook));
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("A8");
    ASSERT_EQ(chessman->getType(), ChessmanType(rook));
    ASSERT_EQ(chessman->isWhite(), false);
}

TEST_F(BoardTest, shouldHaveKnightsInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("B1");
    ASSERT_EQ(chessman->getType(), ChessmanType(knight));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("G1");
    ASSERT_EQ(chessman->getType(), ChessmanType(knight));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("B8");
    ASSERT_EQ(chessman->getType(), ChessmanType(knight));
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("G8");
    ASSERT_EQ(chessman->getType(), ChessmanType(knight));
    ASSERT_EQ(chessman->isWhite(), false);
}

TEST_F(BoardTest, shouldHaveBishopsInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("C1");
    ASSERT_EQ(chessman->getType(), ChessmanType(bishop));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("F1");
    ASSERT_EQ(chessman->getType(), ChessmanType(bishop));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("C8");
    ASSERT_EQ(chessman->getType(), ChessmanType(bishop));
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("F8");
    ASSERT_EQ(chessman->getType(), ChessmanType(bishop));
    ASSERT_EQ(chessman->isWhite(), false);
}

TEST_F(BoardTest, shouldHaveQueenAndKingInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("D1");
    ASSERT_EQ(chessman->getType(), ChessmanType(queen));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("E1");
    ASSERT_EQ(chessman->getType(), ChessmanType(king));
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("D8");
    ASSERT_EQ(chessman->getType(), ChessmanType(queen));
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("E8");
    ASSERT_EQ(chessman->getType(), ChessmanType(king));
    ASSERT_EQ(chessman->isWhite(), false);
}

TEST_F(BoardTest, shouldHavePawnsInRightPostionOnStart)
{
    for(int i=65;i<73;i++)
    {
        std::stringstream stream;
        std::string coordinates;
        stream <<(char)i <<'2';
        stream >> coordinates;
        Chessman* chessman = board->getChessman(coordinates);
        ASSERT_EQ(chessman->getType(), ChessmanType(pawn));
        ASSERT_EQ(chessman->isWhite(), true);
    }

    for(int i=65;i<73;i++)
    {
        std::stringstream stream;
        std::string coordinates;
        stream <<(char)i <<'7';
        stream >> coordinates;
        Chessman* chessman = board->getChessman(coordinates);
        ASSERT_EQ(chessman->getType(), ChessmanType(pawn));
        ASSERT_EQ(chessman->isWhite(), false);
    }

}

TEST_F(BoardTest, shouldHaveMiddleEmpty)
{
    for(int i=65;i<73;i++)
    {
        for(int j=51;j<55;j++)
        {
            std::stringstream stream;
            std::string coordinates;
            stream <<(char)i <<(char)j;
            stream >> coordinates;
            Chessman* chessman = board->getChessman(coordinates);
            ASSERT_EQ(chessman, nullptr);
        }
    }
}