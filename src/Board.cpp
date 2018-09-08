/**
 * Project: Chess
 * Name: Board.cpp
 * Purpose: Board class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#include <iostream>
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Board.h"

Chessman* Board::getChessman(std::string field)
{
    //first character indicates first coordinate
    //example: A1 -> first coordinate is A, so it will be first column
    auto firstCoordinate = (int)field[0];
    auto secondCoordinate = (int)field[1];
    translateCoordinates(&firstCoordinate, &secondCoordinate);
    return board[firstCoordinate][secondCoordinate];
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
        i[pawnsIndex] = new Pawn(white);

    board[0][kingLineIndex] = new Rook(white);
    board[7][kingLineIndex] = new Rook(white);

    board[1][kingLineIndex] = new Knight(white);
    board[6][kingLineIndex] = new Knight(white);

    board[2][kingLineIndex] = new Bishop(white);
    board[5][kingLineIndex] = new Bishop(white);

    board[3][kingLineIndex] = new Queen(white);
    board[4][kingLineIndex] = new King(white);
}

void Board::printBoard()
{
    /*for(int i=0;i<8;i++)
        std::cout<<"___";
    std::cout<<std::endl;
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
    for(int i=0;i<8;i++)
        std::cout<<"___";*/

}

Chessman *Board::move(std::string from, std::string to)
{
    auto firstCoordinate = (int)from[0];
    auto secondCoordinate = (int)from[1];
    translateCoordinates(&firstCoordinate, &secondCoordinate);
    Chessman* movingChessman = board[firstCoordinate][secondCoordinate];

    if(movingChessman == nullptr)
        return nullptr;
    else
    {
        board[firstCoordinate][secondCoordinate] = nullptr;
        firstCoordinate = (int)to[0];
        secondCoordinate = (int)to[1];
        translateCoordinates(&firstCoordinate, &secondCoordinate);
        Chessman* takenChessman =  board[firstCoordinate][secondCoordinate];
        board[firstCoordinate][secondCoordinate] = movingChessman;
        return takenChessman;
    }
}

void Board::translateCoordinates(int *first, int *second)
{
    //'A' index in ASCII is 65, so if char 'A' means 0 its integer value has to be reduced by 65
    *first = *first- 65;
    //'1' index in ASCII is 49 so if char '1' means 0 its integer value has to be reduced by 49
    *second = *second - 49;
}

