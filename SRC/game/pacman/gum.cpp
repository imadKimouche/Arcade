/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** gum
*/

#include "gum.hpp"

gum::gum(int x, int y)
{
    Coordonnes_t c;
    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(x, y);
    c.x = 3 * 32;
    c.y = 2 * 32;
    setCoordImg(c);
    c.x = 32;
    c.y = 32;
    setSize(c);
    setTermpic("|");
}

gum::~gum()
{
}

void gum::update()
{
}
