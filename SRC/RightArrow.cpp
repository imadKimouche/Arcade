/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** right  arrow
*/

#include "RightArrow.hpp"

RightArrow::RightArrow()
{
    Coordonnes_t c;
    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(23, 15);
    c.x = 1310;
    c.y = 401;
    setCoordImg(c);
    c.x = 28;
    c.y = 28;
    setSize(c);
    setTermpic(">");
}

RightArrow::~RightArrow()
{
}

void RightArrow::update()
{
}
