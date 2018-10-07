/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Chessman.h"

class Queen : public Chessman{
public:

   Queen(bool white, Board *board);

    std::vector<Move *> getPossibleMoves() override;
};


#endif //CHESS_QUEEN_H
