/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include "Pawn.h"

std::vector<std::tuple<int, int>> Pawn::getPossibleMoves(Board *board, int x, int y)
{
    std::vector<std::tuple<int, int>> possibleMoves;
    int directionModifier;
    int startingLine;
    if(white)
    {
        directionModifier = 1; //white Pawns moves to the top so they y value will be increased;
        startingLine = 1;
    }
    else
    {
        directionModifier = -1; //black Pawns moves to the bottom so they y value will be decreased;
        startingLine = 6;
    }

    if(board->getChessman(x, y+directionModifier)== nullptr)
    {
        possibleMoves.emplace_back(x, y+directionModifier);
        if(y==startingLine && board->getChessman(x, y+(2*directionModifier))== nullptr)
            possibleMoves.emplace_back(x, y+(2*directionModifier));
    }

    if(x<7)
    {
        Chessman* chessman = board->getChessman(x+1, y+directionModifier);
        if(chessman!= nullptr && (chessman->isWhite()!=this->isWhite()))
        {
            possibleMoves.emplace_back(x+1, y+(directionModifier));
        }
    }

    if(x>0)
    {
        Chessman* chessman = board->getChessman(x-1, y+directionModifier);
        if(chessman!= nullptr && (chessman->isWhite()!=this->isWhite()))
        {
            possibleMoves.emplace_back(x-1, y+(directionModifier));
        }
    }

    return possibleMoves;
}

Pawn::Pawn(bool white) : Chessman(white) {}
