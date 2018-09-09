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
#include <tuple>
#include "Board.h"

class Board;

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
    * @param type - enum indicating type of Chessman
    */
    explicit Chessman(bool white);

    virtual std::vector<std::tuple<int, int>> getPossibleMoves(Board *board, int x, int y) =0;

    /**
    * white getter
    *
    * @return true if Chessman is white; false otherwise
    */
    bool isWhite() const;

    virtual ~Chessman() = default;

protected:
    bool white;
};

#endif //CHESS_CHESSMAN_H



