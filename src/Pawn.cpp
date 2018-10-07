/**
 * Project: Chess
 * Name: Pawn.cpp
 * Purpose: Implementation of
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.1 07.10.2018
*/

#include <Pawn.h>
#include <EnPassantMove.h>

#include "Pawn.h"
#include "RegularMove.h"

std::vector<Move *> Pawn::getPossibleMoves()
{
    if(lastMove!= nullptr && board->getLastMove()==lastMove)
        return possibleMoves;
    else
    {
        lastMove = board->getLastMove();
        if(canMoveForwardOneField())
        {
            possibleMoves.push_back(new RegularMove(x, y, x, y+directionModifier));
            if(canMoveForwardTwoFields())
                possibleMoves.push_back(new RegularMove(x, y, x, y+(2*directionModifier)));
        }

        attackLeft();
        attackRight();
    }

    return possibleMoves;
}


bool Pawn::canMoveForwardOneField() {
    return board->getChessman(x, y+directionModifier)== nullptr;
}

bool Pawn::canMoveForwardTwoFields() {
    return (y==startingLine && board->getChessman(x, y+(2*directionModifier))== nullptr);
}

void Pawn::attackRight() {
    if(x<7) {
        Chessman *chessman = board->getChessman(x + 1, y + directionModifier);
        if((chessman != nullptr && (chessman->isWhite() != this->isWhite())))
            possibleMoves.push_back(new RegularMove(x, y, x+1, y+(directionModifier)));
        else if(lastMoveWasTwoFieldsByEnemyPawnOnTheRight() && y==startingLine+(3*directionModifier))
            possibleMoves.push_back(new EnPassantMove(x, y, x+1, y+(directionModifier)));
    }
}

void Pawn::attackLeft() {
    if(x>0) {
        Chessman *chessman = board->getChessman(x - 1, y + directionModifier);
        if((chessman != nullptr && (chessman->isWhite() != this->isWhite())))
            possibleMoves.push_back(new RegularMove(x, y, x-1, y+(directionModifier)));
        else if(y==startingLine+(3*directionModifier) && lastMoveWasTwoFieldsByEnemyPawnOnTheLeft())
            possibleMoves.push_back(new EnPassantMove(x, y, x-1, y+(directionModifier)));
    }
}

Pawn::Pawn(bool white, Board *board) : Chessman(white, board)
{
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
}

bool Pawn::lastMoveWasTwoFieldsByEnemyPawnOnTheLeft() {
    Move*  move = board->getLastMove();
    if(move== nullptr)
        return false;
    Chessman* movedChessman = board->getChessman(move->getXTo(), move->getYTo());
    return
        (dynamic_cast<Pawn*>(movedChessman)!= nullptr)
        && move->getXTo()==move->getXFrom()
        && abs(move->getYFrom()-move->getYTo())==2
        && move->getXTo()-this->x == -1;
}

bool Pawn::lastMoveWasTwoFieldsByEnemyPawnOnTheRight() {
    Move*  move = board->getLastMove();
    if(move== nullptr)
        return false;
    Chessman* movedChessman = board->getChessman(move->getXTo(), move->getYTo());
    return
            (dynamic_cast<Pawn*>(movedChessman)!= nullptr)
            && move->getXTo()==move->getXFrom()
            && abs(move->getYFrom()-move->getYTo())==2
            && move->getXTo()-this->x == 1;
}
