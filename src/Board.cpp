/**
 * Project: Chess
 * Name: Board.cpp
 * Purpose: Board class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#include <Board.h>
#include <iostream>

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

    for (auto &i : board)
        i[pawnsIndex] = new Chessman(white, ChessmanType(pawn));

    board[0][kingLineIndex] = new Chessman(white, ChessmanType(rook));
    board[7][kingLineIndex] = new Chessman(white, ChessmanType(rook));

    board[1][kingLineIndex] = new Chessman(white, ChessmanType(knight));
    board[6][kingLineIndex] = new Chessman(white, ChessmanType(knight));

    board[2][kingLineIndex] = new Chessman(white, ChessmanType(bishop));
    board[5][kingLineIndex] = new Chessman(white, ChessmanType(bishop));

    board[3][kingLineIndex] = new Chessman(white, ChessmanType(queen));
    board[4][kingLineIndex] = new Chessman(white, ChessmanType(king));
}

void Board::printBoard()
{
    for(auto &i : board)
    {
        for(auto &j : i)
        {
            if(j == nullptr)
                std::cout<<"[ ]";
            else
            {
                if(j->getType()==ChessmanType(king)) std::cout<<"[K]";
                else if(j->getType()==ChessmanType(queen)) std::cout<<"[Q]";
                else if(j->getType()==ChessmanType(rook)) std::cout<<"[R]";
                else if(j->getType()==ChessmanType(knight)) std::cout<<"[N]";
                else if(j->getType()==ChessmanType(pawn)) std::cout<<"[P]";
                else if(j->getType()==ChessmanType(bishop)) std::cout<<"[B]";
            }
        }
        std::cout<<std::endl;
    }

}

