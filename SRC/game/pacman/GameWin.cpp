/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** game over layer
*/

#include "GameWin.hpp"

GameWin::GameWin()
{
    Coordonnes_t c;
    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(10, 16);
    c.x = 0;
    c.y = 8 * 33;
    setCoordImg(c);
    c.x = 307;
    c.y = 214;
    setSize(c);
    setTermpic("YOU WON !");
}

GameWin::~GameWin()
{
}

void GameWin::update()
{
}
