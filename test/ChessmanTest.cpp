#include <Chessman.h>
#include "gtest/gtest.h"
#include "ChessmanType.h"


class ChessmanTest : public ::testing::Test {
public:
    ChessmanTest()
    {
        chessman = new Chessman(true, ChessmanType(queen));
    }

    ~ChessmanTest() override
    {
        delete(chessman);
    }

    Chessman* getChessman() const {
        return chessman;
    }

private:
    Chessman* chessman;
};

TEST_F(ChessmanTest, shouldBeWhite)
{
    ASSERT_EQ(getChessman()->isWhite(), true);
}

TEST_F(ChessmanTest, shouldBeQueen)
{
    ASSERT_EQ(getChessman()->getType(), ChessmanType(queen));
}