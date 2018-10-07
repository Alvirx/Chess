/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 04.10.2018
*/
//

#ifndef CHESS_ENPASSANTMOVE_H
#define CHESS_ENPASSANTMOVE_H


#include "Move.h"

class EnPassantMove : public Move {
public:
    EnPassantMove(int xFrom, int yFrom, int xTo, int yTo);

    bool execute(Board *board) override;

    bool undo(Board *board) override;

};


#endif //CHESS_ENPASSANTMOVE_H
