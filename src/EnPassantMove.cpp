/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 04.10.2018
*/
//

#include "EnPassantMove.h"

bool EnPassantMove::execute(Board *board) {
    Chessman* movingChessman = board->getChessman(xFrom, yFrom);

    takenChessman = board->getChessman(xTo, yFrom);

    if(movingChessman == nullptr)
        return false;
    else
    {
        if(takenChessman!= nullptr)
        {
            if(takenChessman->isWhite()==movingChessman->isWhite())
                return false;
            else
                takenChessman->remove();
            movingChessman->set(xTo, yTo);
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool EnPassantMove::undo(Board *board) {
    Chessman* movingChessman = board->getChessman(xTo, yTo);
    if(movingChessman == nullptr)
        return false;
    else
    {
        if(takenChessman!= nullptr)
            takenChessman->setOnBoard(xTo, yFrom, board);
        else
            return false;
        movingChessman->set(xFrom, yFrom);
    }
    return true;
}

EnPassantMove::EnPassantMove(int xFrom, int yFrom, int xTo, int yTo) : Move(xFrom, yFrom, xTo, yTo) {}
