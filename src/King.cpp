/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include "King.h"

std::vector<Move *> King::getPossibleMoves() {
    std::vector<Move*> possibleMoves;
    return possibleMoves;
}



King::King(bool white, Board *board) : Chessman(white, board) {}
