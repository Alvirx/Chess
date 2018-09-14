/**
 * Project: Chess
 * Name: Move.h
 * Purpose: Storing data of moves done in game
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 10.09.2018
*/
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H


#include "Chessman.h"

class Chessman;

class Move{
public:
    Move(int xFrom, int yFrom, int xTo, int yTo, Chessman *takenChessman) : xFrom(xFrom), yFrom(yFrom), xTo(xTo),
                                                                            yTo(yTo), takenChessman(takenChessman) {}

    int getXFrom() const {
        return xFrom;
    }

    int getYFrom() const {
        return yFrom;
    }

    int getXTo() const {
        return xTo;
    }

    int getYTo() const {
        return yTo;
    }

    Chessman *getTakenChessman() const {
        return takenChessman;
    };

private:
    int xFrom;
    int yFrom;
    int xTo;
    int yTo;
    Chessman* takenChessman;
};


#endif //CHESS_MOVE_H
