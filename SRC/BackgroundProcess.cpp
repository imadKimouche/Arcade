/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** Process
*/

#include "BackgroundProcess.hpp"

BackgroundProcess::BackgroundProcess()
{
    Coordonnes_t c;
    c.x = 0;
    c.y = 0;
    place(0, 0);
    setCoordImg(c);
    c.x = 1280;
    c.y = 720;
    setSize(c);
}

void BackgroundProcess::update()
{
}
