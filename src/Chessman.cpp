/**
 * Project: Chess
 * Name: Chessman.cpp
 * Purpose: Chessman class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/
#include <Chessman.h>

#include "Chessman.h"



bool Chessman::isWhite() const {
    return white;
}

Chessman::Chessman(bool white, Board *board) : white(white), board(board) {
    x = -1;
    y = -1;
    lastMove = nullptr;
}

void Chessman::set(int x, int y)
{
    if(board== nullptr)
        return;

    if(x!=-1 && y!=-1)
        board->setChessman(this->x, this->y, nullptr);

    this->x = x;
    this->y = y;
    board->setChessman(x, y, this);
}

int Chessman::getX() const {
    return x;
}

int Chessman::getY() const {
    return y;
}

void Chessman::remove()
{
    board->setChessman(x, y, nullptr);
    this->x = -1;
    this->y = -1;
}

void Chessman::setOnBoard(int x, int y, Board *board)
{
    this->board = board;
    set(x, y);
}








