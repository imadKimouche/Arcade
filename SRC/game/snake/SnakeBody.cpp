/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** SnakeBody.cpp
*/

#include "Snake.hpp"

SnakeBody::SnakeBody(SnakeHead *origin, int left, int x, int y)
{
    this->head = origin;
    this->first = false;
    this->game = this->head->getGame();
    this->x = x;
    this->y = y;
    this->growWait = 0;
    this->setTermpic("o");
    if (left > 0){
        this->setCoordImg(SBodyLR);
        this->front = 'L';
        this->behind = 'R';
        this->next = new SnakeBody(origin, left - 1, x + 1, y);
    }
    else {
        this->setCoordImg(SBodyLE);
        this->front = 'L';
        this->behind = 'E';
        this->next = nullptr;
    }
    this->setSize(sizeM);
    this->place(this->x, this->y);
    this->game->addObjects(this);
}

SnakeBody::SnakeBody(SnakeHead *origin, char front, int x, int y)
{
    this->head = origin;
    this->game = this->head->getGame();
    this->setTermpic("o");
    this->x = x;
    this->first = false;
    this->y = y;
    this->growWait = 0;
    this->next = nullptr;
    this->front = front;
    this->behind = 'E';
    this->next = nullptr;
    this->setSize(sizeM);
    this->place(this->x, this->y);
    this->game->addObjects(this);
}

void SnakeBody::SnakeBody::isFirst()
{
    this->first = true;
}

void SnakeBody::SnakeBody::update()
{
    return;
}

void SnakeBody::SnakeBody::addgrowWait(int var)
{
    this->growWait += var;
}

void SnakeBody::SnakeBody::autoSetSprite()
{
    if (behind == 'U'){
        this->setCoordImg(SBodyUD);
    }
    if (behind == 'D'){
        this->setCoordImg(SBodyUD);
    }
    if (behind == 'L'){
        this->setCoordImg(SBodyLR);
    }
    if (behind == 'R'){
        this->setCoordImg(SBodyLR);
    }
    if ((front == 'U' && behind == 'E') || (front == 'E' && behind == 'U')){
        this->setCoordImg(SBodyUE);
    }
    if ((front == 'R' && behind == 'E') || (front == 'E' && behind == 'R')){
        this->setCoordImg(SBodyRE);
    }
    if ((front == 'D' && behind == 'E') || (front == 'E' && behind == 'D')){
        this->setCoordImg(SBodyDE);
    }
    if ((front == 'L' && behind == 'E') || (front == 'E' && behind == 'L')){
        this->setCoordImg(SBodyLE);
    }
}

void SnakeBody::SnakeBody::move(SnakeHead *head, int x, int y, char _front, char _behind)
{
    if (this->next != nullptr)
        this->next->move(this->head, this->x, this->y, this->front, this->behind);
    else if (this->growWait > 0){
            this->next = new SnakeBody(this->head, this->front, x, y);
            this->growWait--;
    }
    if (this->growWait > 0 && this->next){
        this->next->addgrowWait(this->growWait);
        this->growWait = 0;
    }
    this->x = x;
    this->y = y;
    this->head = head;
    this->front = _front;
    this->behind = _behind;
    if (!this->next)
        this->behind = 'E';
    Coordonnes_t loc = {this->x, this->y};
    this->go(loc);
    this->autoSetSprite();
}

void SnakeBody::SnakeBody::eat(int value)
{
    if (value > 0){
        if (this->next){
            this->next->eat(value);
        }
        else
            this->growWait = value;
    }
}

bool SnakeBody::SnakeBody::isHere(int tx, int ty)
{
    if (tx == this->x && ty == this->y){
        return true;
    }
    if (this->next)
        return this->next->isHere(tx, ty);
    return false;
}