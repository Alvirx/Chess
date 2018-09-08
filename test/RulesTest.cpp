/**
 * Project: Chess
 * Name: RulesTest.cpp
 * Purpose: Testing Rules class functionality
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include <Rules.h>
#include <Board.h>
#include <Rook.h>
#include <Knight.h>
#include <Bishop.h>
#include <King.h>
#include <Queen.h>
#include <Pawn.h>
#include "gtest/gtest.h"

/**
 * Fixture that creates, stores and deletes tested instance of Chessman
 */
class RulesTest : public ::testing::Test {
public:
    /**
     * Creates white queen chessman
     */
    RulesTest()
    {
        rules = new Rules(new Board());
    }
    /**
     * deletes chessman
     */
    ~RulesTest() override
    {
        delete(rules);
    }

    Rules* rules;
};

/**
 * Tests if on the beginning, on the "A1" and "H1" fields are white rook Chessmen
 * and on the "H8" and "A8" are black rook Chessmen
 */
TEST_F(RulesTest, boardShouldHaveRooksInRightPostionOnStart)
{
    Chessman* chessman = rules->getChessman("A1");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("H1");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("H8");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = rules->getChessman("A8");
    ASSERT_NE(dynamic_cast<Rook*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}

/**
 * Tests if on the beginning, on the "B1" and "G1" fields are white knight Chessmen
 * and on the "G8" and "B8" are black knight Chessmen
 */
TEST_F(RulesTest, boardShouldHaveKnightsInRightPostionOnStart)
{
    Chessman* chessman = rules->getChessman("B1");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("G1");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("B8");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = rules->getChessman("G8");
    ASSERT_NE(dynamic_cast<Knight*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}

/**
 * Tests if on the beginning, on the "C1" and "F1" fields are white bishop Chessmen
 * and on the "C8" and "F8" are black bishop Chessmen
 */
TEST_F(RulesTest, boardShouldHaveBishopsInRightPostionOnStart)
{
    Chessman* chessman = rules->getChessman("C1");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("F1");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("C8");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = rules->getChessman("F8");
    ASSERT_NE(dynamic_cast<Bishop*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}

/**
 * Tests if on the beginning, on the "D1" is white queen Chessmen and on the "E1" field is white king Chessmen
 * and on the "D8" is black queen Chessmen and on the "E8" field is black king Chessmen
 */
TEST_F(RulesTest, boardShouldHaveQueenAndKingInRightPostionOnStart)
{
    Chessman* chessman = rules->getChessman("D1");
    ASSERT_NE(dynamic_cast<Queen*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("E1");
    ASSERT_NE(dynamic_cast<King*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), true);

    chessman = rules->getChessman("D8");
    ASSERT_NE(dynamic_cast<Queen*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);

    chessman = rules->getChessman("E8");
    ASSERT_NE(dynamic_cast<King*>(chessman), nullptr);
    ASSERT_EQ(chessman->isWhite(), false);
}

/**
 * Tests if on the beginning, on the second row there is a line of white pawns
 * and on the seventh row there is a line of black pawns
 */
TEST_F(RulesTest, boardShouldHavePawnsInRightPostionOnStart)
{
    for(int i=65;i<73;i++)
    {
        std::stringstream stream;
        std::string coordinates;
        stream <<(char)i <<'2';
        stream >> coordinates;
        Chessman* chessman = rules->getChessman(coordinates);
        ASSERT_NE(dynamic_cast<Pawn*>(chessman), nullptr);
        ASSERT_EQ(chessman->isWhite(), true);
    }

    for(int i=65;i<73;i++)
    {
        std::stringstream stream;
        std::string coordinates;
        stream <<(char)i <<'7';
        stream >> coordinates;
        Chessman* chessman = rules->getChessman(coordinates);
        ASSERT_NE(dynamic_cast<Pawn*>(chessman), nullptr);
        ASSERT_EQ(chessman->isWhite(), false);
    }

}

/**
 * Tests if on the beginning rows from third to sixth are empty
 */
TEST_F(RulesTest, boardShouldHaveMiddleEmpty)
{
    for(int i=65;i<73;i++)
    {
        for(int j=51;j<55;j++)
        {
            std::stringstream stream;
            std::string coordinates;
            stream <<(char)i <<(char)j;
            stream >> coordinates;
            Chessman* chessman = rules->getChessman(coordinates);
            ASSERT_EQ(chessman, nullptr);
        }
    }
}