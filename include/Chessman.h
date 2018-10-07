/**
 * Project: Chess
 * Name: Chessman.h
 * Purpose: Chessman class header
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#ifndef CHESS_CHESSMAN_H
#define CHESS_CHESSMAN_H


#include <vector>
#include "Board.h"
#include "Move.h"

class Board;
class Move;
/**
 * Class that stores information about particular Chessman
 * and allows to retrieve information form its instances
 */
class Chessman {
public:

    /**
    * Constructs Chessman
    *
    * @param white - boolean value, if true indicates Chessman as white; black otherwise
    * @param board - board where chessman stay
    */
    explicit Chessman(bool white, Board *board);

    /**
     * sets Chessman on chosen position
     * @param x - X coordinate on board
     * @param y - Y coordinate on board
     */
    void set(int x, int y);

    void remove();

    void setOnBoard(int x, int y, Board* board);

    /**
     * Calculates possible moves
     * @return vector of possible moves
     */
    virtual std::vector<Move *> getPossibleMoves() =0;



    /**
    * white getter
    *
    * @return true if Chessman is white; false otherwise
    */
    bool isWhite() const;

    virtual ~Chessman() = default;

    int getX() const;

    int getY() const;

protected:
    bool white;
    int x;
    int y;
    Board* board;
    std::vector<Move*> possibleMoves;
    Move* lastMove;
};

#endif //CHESS_CHESSMAN_H



