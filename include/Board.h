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
#include <stack>
#include "Move.h"
#include "Chessman.h"

class Move;
class Chessman;

/**
 * Class storing board`s fields and Chessmen data
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
     * @param move - move to do
     */
    void move(Move* move);

    Move* getLastMove();

    void undo();

    void redo();


private:
    Chessman* board[8][8];
    std::stack<Move*> movesDone;
    std::stack<Move*> movesToDo;
};


#endif //CHESS_BOARD_H

