/**
 * Project: Chess Tests
 * Name: ChessmanTest.cpp
 * Purpose: Testing all Chessman`s methods
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/
#include <Chessman.h>
#include "gtest/gtest.h"
#include "ChessmanType.h"

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
        chessman = new Chessman(true, ChessmanType(queen));
    }
    /**
     * deletes chessman
     */
    ~ChessmanTest() override
    {
        delete(chessman);
    }

    /**
     *
     * @return white queen chessman
     */
    Chessman* getChessman() const {
        return chessman;
    }

private:
    Chessman* chessman;
};

/**
 * Checks if chessman properly returns information about its color
 */
TEST_F(ChessmanTest, shouldBeWhite)
{
    ASSERT_EQ(getChessman()->isWhite(), true);
}
/**
 * Checks if chessman properly returns information about its type
 */
TEST_F(ChessmanTest, shouldBeQueen)
{
    ASSERT_EQ(getChessman()->getType(), ChessmanType(queen));
}