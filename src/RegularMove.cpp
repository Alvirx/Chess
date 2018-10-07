/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 02.10.2018
*/
//

#include "RegularMove.h"

bool RegularMove::execute(Board *board)
{
    Chessman* movingChessman = board->getChessman(xFrom, yFrom);
    takenChessman = board->getChessman(xTo, yTo);

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
        }
        movingChessman->set(xTo, yTo);
    }
    return true;
}

bool RegularMove::undo(Board *board)
{
    Chessman* movingChessman = board->getChessman(xTo, yTo);
    if(movingChessman == nullptr)
        return false;
    else
    {
        if(takenChessman!= nullptr)
            takenChessman->setOnBoard(xTo, yTo, board);
        movingChessman->set(xFrom, yFrom);
    }
    return true;
}

RegularMove::RegularMove(int xFrom, int yFrom, int xTo, int yTo) : Move(xFrom, yFrom, xTo, yTo) {}
