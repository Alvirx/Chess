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
class Board;
class Move{
public:
    Move(int xFrom, int yFrom, int xTo, int yTo) :
    xFrom(xFrom),
    yFrom(yFrom),
    xTo(xTo),
    yTo(yTo)
    {
        takenChessman = nullptr;
    }

    /**
     * Executes move on specified board
     * @param board - board where move should be done
     * @return true if move was executed correctly, false if something went wrong and move has not been done
     */
    virtual bool execute(Board* board)=0;

    /**
     * Undo the move that was done
     * @param board - board where move should be undone
     * @return true if move was undone correctly, false if something went wrong and move has not been undone
     */
    virtual bool undo(Board* board)=0;

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

    bool operator()(const Move *rhs) const {
        return xFrom == rhs->xFrom &&
               yFrom == rhs->yFrom &&
               xTo == rhs->xTo &&
               yTo == rhs->yTo;
    }

protected:
    int xFrom;
    int yFrom;
    int xTo;
    int yTo;
    Chessman* takenChessman;
};


#endif //CHESS_MOVE_H
