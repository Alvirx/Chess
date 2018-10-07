/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H


#include "Chessman.h"

class Bishop : public Chessman {
public:

    Bishop(bool white, Board *board);

    std::vector<Move *> getPossibleMoves() override;

};


#endif //CHESS_BISHOP_H
