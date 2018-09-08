#include <Board.h>
#include <utility>

/**
 * Project: Chess
 * Name: Rules.cpp
 * Purpose: Rules class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 08.09.2018
*/
//

#include <Rules.h>
#include <Pawn.h>
#include <Rook.h>
#include <Knight.h>
#include <Bishop.h>
#include <Queen.h>
#include <King.h>

#include "Rules.h"

Rules::Rules(Board *board) : board(board)
{
    generateChessmen(true);
    generateChessmen(false);
}

Rules::~Rules()
{
    delete(board);
}

Chessman *Rules::getChessman(std::string field)
{
    return board->getChessman(getX(field), getY(field));
}

void Rules::generateChessmen(bool white)
{
    int pawnsIndex;
    int kingLineIndex;
    if(white)
    {
        pawnsIndex = 1;
        kingLineIndex = 0;
    }
    else
    {
        pawnsIndex = 6;
        kingLineIndex = 7;
    }

    for (int i=0;i<8;i++)
        board->setChessman(i,pawnsIndex, new Pawn(white));

    board->setChessman(0, kingLineIndex, new Rook(white));
    board->setChessman(7, kingLineIndex, new Rook(white));

    board->setChessman(1, kingLineIndex, new Knight(white));
    board->setChessman(6, kingLineIndex, new Knight(white));
    board->setChessman(2, kingLineIndex, new Bishop(white));
    board->setChessman(5, kingLineIndex, new Bishop(white));
    board->setChessman(3, kingLineIndex, new Queen(white));
    board->setChessman(4, kingLineIndex, new King(white));
}

int Rules::getX(std::string field)
{
    //'A' index in ASCII is 65, so if char 'A' means 0 its integer value has to be reduced by 65
    // or like in this case by 'A' value
    return (int)field[0] - (int)'A';
}

int Rules::getY(std::string field)
{
    //'1' index in ASCII is 49 so if char '1' means 0 its integer value has to be reduced by 49
    // or like in this case by 'A' value
    return (int)field[1] - (int)'1';
}

