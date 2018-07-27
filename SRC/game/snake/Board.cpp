/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** Board.cpp
*/

#include "Snake.hpp"

Board::Board(SnakeGame *game)
{
    this->game = game;
    this->size_x = 20;
    this->size_y = 20;
    this->setCoordImg({5 * 32, 0 * 32});
    this->setSize({32 * this->size_x, this->size_y * 32});
    this->food = nullptr;
    this->place(0, 1);
}

void Board::Board::update()
{
    return;
}

void Board::Board::init()
{
    this->food = new Food(this->game);
}

int Board::Board::getX()
{
    return this->size_x;
}

int Board::Board::getY()
{
    return this->size_y;
}

bool Board::Board::isLegal(int x, int y)
{
    if (x >= 0 && x < size_x){
        if (y >= 1 && y < size_y + 1){
            return true;
        }
    }
    return false;
}

int Board::Board::getFood(int x, int y)
{
    if (this->food->isIn(x, y)){
        return this->food->getValue();
    }
    return 0;
}