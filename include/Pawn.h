/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/


#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Chessman.h"

class Pawn : public Chessman{
public:
    explicit Pawn(bool white);

    std::vector<std::tuple<int, int>> getPossibleMoves(Board *board, int x, int y) override;

};


#endif //CHESS_PAWN_H
