/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Livestxt
*/

#include "LivesTxt.hpp"

#include <iostream>

Livestxt::Livestxt()
{
    Coordonnes_t c;
    setFont(PFont_t{255, 255, 255, 255, 32, "./fonts/ka1.ttf"});
    place(20, 30);
    c.x = -200;
    setCoordImg(c);
    c.x = 35;
    setSize(c);

    setTermpic("Lives ");
}

Livestxt::~Livestxt()
{
}

void Livestxt::update()
{
}
