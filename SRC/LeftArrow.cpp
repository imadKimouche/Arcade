/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** left arrow
*/

#include "LeftArrow.hpp"

LeftArrow::LeftArrow()
{
    Coordonnes_t c;
    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(14, 15);
    c.x = 1280;
    c.y = 401;
    setCoordImg(c);
    c.x = 28;
    c.y = 28;
    setSize(c);
    setTermpic("<");
}

LeftArrow::~LeftArrow()
{
}

void LeftArrow::update()
{
}
