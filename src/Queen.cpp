/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/

#include "Queen.h"

std::vector<Move *> Queen::getPossibleMoves() {
    std::vector<Move*> possibleMoves;
    return possibleMoves;
}



Queen::Queen(bool white, Board *board) : Chessman(white, board) {}
