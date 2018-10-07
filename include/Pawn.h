/**
 * Project: Chess
 * Name: Pawn.h
 * Purpose: Pawn class header
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/


#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Chessman.h"

class Pawn : public Chessman{
public:
    Pawn(bool white, Board *board);

    std::vector<Move *> getPossibleMoves() override;

private:
    int directionModifier;
    int startingLine;

    bool canMoveForwardOneField();
    bool canMoveForwardTwoFields();
    void attackRight();
    void attackLeft();
    bool lastMoveWasTwoFieldsByEnemyPawnOnTheLeft();
    bool lastMoveWasTwoFieldsByEnemyPawnOnTheRight();
};


#endif //CHESS_PAWN_H

/*
 * class Player
 * Game* game;
 * Field11.onlick = game->getPossibleMoves(Field11.chessman); ------->> return chessman.getPossibleMoves()
 */