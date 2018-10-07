/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include <Rook.h>

#include "Rook.h"

std::vector<Move *> Rook::getPossibleMoves()
{
    std::vector<Move*> possibleMoves;
    return possibleMoves;
}



Rook::Rook(bool white, Board *board) : Chessman(white, board) {}


