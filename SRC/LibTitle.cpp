/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** lib title
*/

#include "LibTitle.hpp"

LibTitle::LibTitle(const std::string &str)
{
    Coordonnes_t c;

    setFont(PFont_t{178, 0, 89, 255, 25, "./fonts/ka1.ttf"});
    place(15, 17);
    c.x = -200;
    c.y = 480;
    setCoordImg(c);
    c.x = 32;
    setSize(c);
    setTermpic(str);
}

LibTitle::~LibTitle()
{
}

void LibTitle::update()
{
}
