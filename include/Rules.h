/**
 * Project: Chess
 * Name: Rules.h
 * Purpose: Menage rules on board (how counters are set on the beginning,
 * how procedure of calculating possible moves looks like etc.
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#ifndef CHESS_RULES_H
#define CHESS_RULES_H


#include "Board.h"

class Chessman;
class Board;

class Rules {
public:
    explicit Rules(Board* board);
    ~Rules();

    Chessman* getChessman(std::string field);

private:
    Board* board;
    void generateChessmen(bool white);
    /*void translateCoordinates(int *first, int *second);*/
    int getX(std::string field);
    int getY(std::string field);
};


#endif //CHESS_RULES_H
