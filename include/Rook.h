/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H


#include "Chessman.h"

class Rook : public Chessman{
public:

    Rook(bool white, Board *board);

    std::vector<Move *> getPossibleMoves() override;

};


#endif //CHESS_ROOK_H
