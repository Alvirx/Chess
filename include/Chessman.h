#ifndef CHESS_CHESSMAN_H
#define CHESS_CHESSMAN_H
#include "ChessmanType.h"


class Chessman {
public:
    Chessman(bool isWhite, ChessmanType type);
private:
    ChessmanType type;
    bool white;
public:
    ChessmanType getType() const;

    bool isWhite() const;
};


#endif //CHESS_CHESSMAN_H
