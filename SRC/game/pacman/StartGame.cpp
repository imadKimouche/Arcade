/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** start Game layer
*/

#include "StartGame.hpp"

StartGame::StartGame()
{
    Coordonnes_t c;
    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(10, 16);
    c.x = 0;
    c.y = 6 * 32;
    setCoordImg(c);
    c.x = 307;
    c.y = 34;
    setSize(c);
    setTermpic("GET READY!");
}

StartGame::~StartGame()
{
}

void StartGame::update()
{
}
