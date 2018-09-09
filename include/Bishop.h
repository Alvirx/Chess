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
    explicit Bishop(bool white);

    std::vector<std::tuple<int, int>> getPossibleMoves(Board *board, int x, int y) override;

};


#endif //CHESS_BISHOP_H
