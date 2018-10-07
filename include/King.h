/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#ifndef CHESS_KING_H
#define CHESS_KING_H


#include "Chessman.h"

class King : public Chessman{
public:

    King(bool white, Board *board);

    std::vector<Move *> getPossibleMoves() override;

};


#endif //CHESS_KING_H
