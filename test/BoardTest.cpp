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
 * Tests if on the beginning, on the "A1" and "H1" fields are white rook Chessmen
 * and on the "H8" and "A8" are black rook Chessmen
 */
TEST_F(BoardTest, shouldHaveRooksInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("A1");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("H1");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("H8");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("A8");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}

/**
 * Tests if on the beginning, on the "B1" and "G1" fields are white knight Chessmen
 * and on the "G8" and "B8" are black knight Chessmen
 */
TEST_F(BoardTest, shouldHaveKnightsInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("B1");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("G1");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("B8");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("G8");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}

/**
 * Tests if on the beginning, on the "C1" and "F1" fields are white bishop Chessmen
 * and on the "C8" and "F8" are black bishop Chessmen
 */

TEST_F(BoardTest, shouldHaveBishopsInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("C1");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("F1");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("C8");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("F8");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}


/**
 * Tests if on the beginning, on the "D1" is white queen Chessmen and on the "E1" field is white king Chessmen
 * and on the "D8" is black queen Chessmen and on the "E8" field is black king Chessmen
 */
TEST_F(BoardTest, shouldHaveQueenAndKingInRightPostionOnStart)
{
    Chessman* chessman = board->getChessman("D1");
    ASSERT_NE(dynamic_cast<Queen*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("E1");
    ASSERT_NE(dynamic_cast<King*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = board->getChessman("D8");
    ASSERT_NE(dynamic_cast<Queen*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = board->getChessman("E8");
    ASSERT_NE(dynamic_cast<King*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}


/**
 * Tests if on the beginning, on the second row there is a line of white pawns
 * and on the seventh row there is a line of black pawns
 */
TEST_F(BoardTest, shouldHavePawnsInRightPostionOnStart)
{
    for(int i=65;i<73;i++)
    {
        std::stringstream stream;
        std::string coordinates;
        stream <<(char)i <<'2';
        stream >> coordinates;
        Chessman* chessman = board->getChessman(coordinates);
        ASSERT_NE(dynamic_cast<Pawn*>(chessman), nullptr);
        ASSERT_EQ(chessman->isWhite(), true);
    }

    for(int i=65;i<73;i++)
    {
        std::stringstream stream;
        std::string coordinates;
        stream <<(char)i <<'7';
        stream >> coordinates;
        Chessman* chessman = board->getChessman(coordinates);
        ASSERT_NE(dynamic_cast<Pawn*>(chessman), nullptr);
        ASSERT_EQ(chessman->isWhite(), false);
    }

}

/**
 * Tests if on the beginning rows from third to sixth are empty
 */

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


/**
 * Tests if "move" method can move pawn to empty field
 */

TEST_F(BoardTest, shouldMoveFromOneFieldToOtherEmptyField)
{
    Chessman* chessman = board->getChessman("E2");
    ASSERT_NE(dynamic_cast<Pawn*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);
    board->move("E2", "E4");
    ASSERT_EQ(board->getChessman("E2"), nullptr);
    ASSERT_EQ(board->getChessman("E4"), chessman);

}


/**
 * Tests if "move" method returns taken Chessman
 */
TEST_F(BoardTest, shouldReturnTakenChessman)
{
    Chessman* blackChessman = board->getChessman("D7");
    Chessman* whiteChessman = board->getChessman("E2");


    board->move("E2", "E4");
    board->move("D7", "D5");
    Chessman* takenChessman = board->move("E4", "D5");
    ASSERT_EQ(takenChessman, blackChessman);
    ASSERT_EQ(board->getChessman("D5"), whiteChessman);
    ASSERT_EQ(board->getChessman("E2"), nullptr);
    ASSERT_EQ(board->getChessman("E4"), nullptr);
    ASSERT_EQ(board->getChessman("D7"), nullptr);
}

/**
 * Tests if "move" method not change anything if "from" field is empty
 */
TEST_F(BoardTest, shouldNotMoveAnythingIfFromFieldIsEmpty)
{
    Chessman* blackChessman = board->getChessman("D7");
    Chessman* whiteChessman = board->getChessman("E2");


    board->move("E2", "E4");
    board->move("D7", "D5");
    Chessman* takenChessman = board->move("D4", "D5");
    ASSERT_EQ(takenChessman, nullptr);
    ASSERT_EQ(board->getChessman("D5"), blackChessman);
    ASSERT_EQ(board->getChessman("E4"), whiteChessman);
    ASSERT_EQ(board->getChessman("E2"), nullptr);
    ASSERT_EQ(board->getChessman("D7"), nullptr);
    ASSERT_EQ(board->getChessman("D4"), nullptr);
}
