/**
 * Project: Chess
 * Name: Board.cpp
 * Purpose: Board class implementation
 *
 * @author Bartosz Gorski "Alvirx"
 * @version 1.0 29.08.2018
*/

#include <iostream>
#include <Board.h>

#include "Board.h"

Chessman* Board::getChessman(int x, int y)
{
    return board[x][y];
}

Board::Board()
{
    //initialize whole board
    for (auto &i : board) {
        for(auto &j : i)
        {
            j = nullptr;
        }
    }
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

void Board::move(Move* move)
{
    move->execute(this);
    movesDone.push(move);
    while (!movesToDo.empty())
        movesToDo.pop();
}

void Board::setChessman(int x, int y, Chessman *chessman)
{
    board[x][y] = chessman;
}

Move *Board::getLastMove() {
    if(movesDone.empty())
        return nullptr;

    return movesDone.top();
}

void Board::undo()
{
    if(movesDone.empty())
        return;
    Move* move = movesDone.top();
    movesDone.pop();
    move->undo(this);
    movesToDo.push(move);
}

void Board::redo()
{
    if(movesToDo.empty())
        return;
    Move* move = movesToDo.top();
    movesToDo.pop();
    move->execute(this);
    movesDone.push(move);
}
/*
//Game??
while(gameIsOn())
{
    currentPlayer->move();
    playerQueue->enquee(currentPlayer);
    currentPlayer = playerQueue->dequeue();
}

//Player
Field* field = choseField();
moves = field->getPossibleMoves();
if(!moves.empty())
{

}
 */