/**
 * Project: Chess
 * Name: Board.h
 * Purpose: Board class header
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <string>
#include "Move.h"
#include "Chessman.h"

class Chessman;

/**
 * Class storing board`s fields, and Chessmen
 */
class Board {
public:

    /**
     * Initializes board with nulls
     */
    Board();


    /**
     * Returns Chessman on particular position
     * @param field chosen
     * @return Chessman staying on given field; null if field is empty
     */
    Chessman* getChessman(int x, int y);

    /**
     * sets Chessman on particular position
     */
    void setChessman(int x, int y, Chessman* chessman);

    /*Temporary method for visualising board*/
    void printBoard();

    /**
     * Moves Chessmen on board
     * @param x1 - X value of field from move starts
     * @param y1 - Y value of field from move starts
     * @param x2 - X value of field where move ends
     * @param y2 - Y value of field where move ends
     * @return taken Chessman if there was Chessman on "to" Field; Null otherwise
     */
    Chessman* move(int x1, int y1, int x2, int y2);

    Move* getLastMove();


private:
    Chessman* board[8][8];
};


#endif //CHESS_BOARD_H

