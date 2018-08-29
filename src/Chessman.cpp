#include "Chessman.h"


Chessman::Chessman(bool white, ChessmanType type)
{
    this->white = white;
    this->type = type;
}

ChessmanType Chessman::getType() const {
    return type;
}

bool Chessman::isWhite() const {
    return white;
}
