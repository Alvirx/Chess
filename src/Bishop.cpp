/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include "Bishop.h"

std::vector<Move *> Bishop::getPossibleMoves() {
    std::vector<Move*> possibleMoves;
    return possibleMoves;
}



Bishop::Bishop(bool white, Board *board) : Chessman(white, board) {}
