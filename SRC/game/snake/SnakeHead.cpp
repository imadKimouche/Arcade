/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** SnakeHead.cpp
*/

#include "Snake.hpp"

SnakeHead::SnakeHead(SnakeGame *game)
{
    this->game = game;
    this->x = 8;
    this->y = 8;
    this->place(this->x, this->y);
    this->setCoordImg(SHeadLEFT);
    this->setTermpic("o");
    this->front = 'L';
    this->behind = 'R';
    this->first = new SnakeBody(this, 3, 9, 8);
    this->first->isFirst();
    this->setSize(sizeH);
}

SnakeGame *SnakeHead::SnakeHead::getGame()
{
    return this->game;
}

void SnakeHead::SnakeHead::update()
{
    return;
}

bool SnakeHead::SnakeHead::moveFinished()
{
    if (this->getTogo().x == this->getCoord().x)
        if (this->getTogo().y == this->getCoord().y)
            return true;
    return false;
}

void SnakeHead::SnakeHead::move()
{
    if (this->front == 'L'){
        if (!this->game->isLegal(this->x - 1, this->y) || this->isHere(this->x - 1, this->y))
            this->game->end();
        else {
            this->setCoordImg(SHeadLEFT);
            this->first->move(this, this->x, this->y, this->front, this->behind);
            this->go({this->x - 1, this->y});
            this->x -= 1;
            this->behind = 'R';
        }
    }
    if (this->front == 'U'){
        if (!this->game->isLegal(this->x, this->y - 1) || this->isHere(this->x, this->y - 1))
            this->game->end();
        else {
            this->setCoordImg(SHeadUP);
            this->first->move(this, this->x, this->y, this->front, this->behind);
            this->go({this->x, this->y - 1});
            this->y -= 1;
            this->behind = 'D';
        }
    }
    if (this->front == 'R'){
        if (!this->game->isLegal(this->x + 1, this->y) || this->isHere(this->x + 1, this->y))
            this->game->end();
        else {
            this->setCoordImg(SHeadRIGHT);
            this->first->move(this, this->x, this->y, this->front, this->behind);
            this->go({this->x + 1, this->y});
            this->x += 1;
            this->behind = 'L';
        }
    }
    if (this->front == 'D'){
        if (!this->game->isLegal(this->x, this->y + 1) || this->isHere(this->x, this->y + 1)){
            this->game->end();
    }
        else {
            this->setCoordImg(SHeadDOWN);
            this->first->move(this, this->x, this->y, this->front, this->behind);
            this->go({this->x, this->y + 1});
            this->y += 1;
            this->behind = 'U';
        }
    }
    eat(this->game->getFood(this->x, this->y));
}

void SnakeHead::SnakeHead::change_face(char direction)
{
    if (direction != this->behind){
        this->front = direction;
    }
}

void SnakeHead::SnakeHead::eat(int value)
{
    this->first->eat(value);
}

bool SnakeHead::SnakeHead::isHere(int tx, int ty)
{
    if (tx == this->x && ty == this->y)
        return true;
    return this->first->isHere(tx, ty);
}