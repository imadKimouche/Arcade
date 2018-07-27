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
    place(10, 16);
    c.x = 0;
    c.y = 7 * 32;
    setCoordImg(c);
    c.x = 307;
    c.y = 34;
    setSize(c);
    setTermpic("GAME OVER");
}

GameOver::~GameOver()
{
}

void GameOver::update()
{
}
