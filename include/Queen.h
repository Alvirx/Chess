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
    explicit Queen(bool white);
    std::vector<int> *getPossibleMoves(Board *board) override;
};


#endif //CHESS_QUEEN_H
