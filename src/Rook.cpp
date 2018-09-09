/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include "Rook.h"

std::vector<std::tuple<int, int>> Rook::getPossibleMoves(Board *board, int x, int y)
{
    std::vector<std::tuple<int, int>> possibleMoves;
    return possibleMoves;
}

Rook::Rook(bool white) : Chessman(white) {}
