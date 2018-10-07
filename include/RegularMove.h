/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 02.10.2018
*/
//

#ifndef CHESS_REGULARMOVE_H
#define CHESS_REGULARMOVE_H

#include "Move.h"

class RegularMove : public Move {
public:
    RegularMove(int xFrom, int yFrom, int xTo, int yTo);

    bool execute(Board *board) override;

    bool undo(Board *board) override;

};


#endif //CHESS_REGULARMOVE_H
