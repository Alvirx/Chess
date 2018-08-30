/**
 * Project: Chess
 * Name: Board.cpp
 * Purpose: Board class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#include <Board.h>

#include "Board.h"

Chessman* Board::getChessman(std::string field)
{
    //first character indicates first coordinate
    //example: A1 -> first coordinate is A, so it will be first column
    char firstCoordinate = field[0];
    char secondCoordinate = field[1];
    //then both Coordinates must be translated to simple integers from 0 to 7

    //'A' index in ASCII is 65, so if char 'A' means 0 its integer value has to be reduced by 65
    int firstIndex = (int)firstCoordinate - 65;
    //'1' index in ASCII is 49 so if char '1' means 0 its integer value has to be reduced by 49
    int secondIndex = (int)secondCoordinate - 49;

    return board[firstIndex][secondIndex];
}

Board::Board()
{
    //initialize middle of the board with nulls
    for (auto &i : board) {
        for(int j=2; j<6; j++)
        {
            i[j] = nullptr;
        }
    }
    //generate white chessmen
    generateChessmen(true);
    //generate black chessmen
    generateChessmen(false);
}

void Board::generateChessmen(bool white)
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

    for (auto &i : board) {
        i[pawnsIndex] = new Chessman(white, ChessmanType(pawn));
    }

    board[kingLineIndex][0] = new Chessman(white, ChessmanType(rook));
    board[kingLineIndex][7] = new Chessman(white, ChessmanType(rook));

    board[kingLineIndex][1] = new Chessman(white, ChessmanType(knight));
    board[kingLineIndex][6] = new Chessman(white, ChessmanType(knight));

    board[kingLineIndex][2] = new Chessman(white, ChessmanType(bishop));
    board[kingLineIndex][5] = new Chessman(white, ChessmanType(bishop));

    board[kingLineIndex][3] = new Chessman(white, ChessmanType(queen));
    board[kingLineIndex][4] = new Chessman(white, ChessmanType(king));
}

