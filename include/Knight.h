/**
 * Project: Chess
 * Name:
 * Purpose: 
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H


#include "Chessman.h"

class Knight : public Chessman{
public:
    explicit Knight(bool white);

    std::vector<std::tuple<int, int>> getPossibleMoves(Board *board, int x, int y) override;

};


#endif //CHESS_KNIGHT_H
