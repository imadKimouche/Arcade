/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** Food.cpp
*/

#include "Snake.hpp"

Food::Food(SnakeGame *game)
{
    this->game = game;
    bool valid = false;
    this->setTermpic("F");
    if (rand() % 100 >= 10)
        type = 1;
    else
        type = 2;
    if (type == 1){
        this->scoreValue = 100;
        this->growValue = 2;
        this->setCoordImg(SFood);
    }
    if (type == 2){
        this->scoreValue = 500;
        this->growValue = 7;
        this->setCoordImg(SFoodG);
    }
    while (!valid){
        this->x = rand() % 30;
        this->y = rand() % 30;
        if (this->game->isLegal(this->x, this->y)){
            if (!this->game->isSnake(this->x, this->y))
                valid = true;
        }
    }
    this->setSize(sizeF);
    this->place(this->x, this->y);
    this->game->addObjects(this);
}

void Food::Food::update()
{
    return;
}

int Food::Food::getValue()
{
    int value = this->growValue;
    this->game->addScore(scoreValue);
    this->reload();
    return value;
}

void Food::Food::reload()
{
    bool valid = false;
    if (rand() % 100 >= 10)
        type = 1;
    else
        type = 2;
    if (type == 1){
        this->scoreValue = 100;
        this->growValue = 2;
        this->setCoordImg(SFood);
    }
    if (type == 2){
        this->scoreValue = 500;
        this->growValue = 7;
        this->setCoordImg(SFoodG);
    }
    while (!valid){
        this->x = rand() % 30;
        this->y = rand() % 30;
        if (this->game->isLegal(this->x, this->y)){
            if (!this->game->isSnake(this->x, this->y))
                valid = true;
        }
    }
    this->place(this->x, this->y);
}

bool Food::Food::isIn(int x, int y)
{
    if (x == this->x && y == this->y)
        return true;
    return false;
}