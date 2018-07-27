/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** game over layer
*/

#include "GameOver.hpp"

GameOver::GameOver()
{
    Coordonnes_t c;
    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(6, 8);
    c.x = 0;
    c.y = 20 * 32;
    setCoordImg(c);
    c.x = 278;
    c.y = 37;
    setSize(c);
    setTermpic("Game Over");
}

GameOver::~GameOver()
{
}

void GameOver::update()
{
}
