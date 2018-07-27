/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Arcade title
*/

#include "ArcadeTitle.hpp"

ArcadeTitle::ArcadeTitle(const std::string &str)
{
    srand(time(nullptr));
    Coordonnes_t c;

    setFont(PFont_t{255, 30, 90, 255, 80, ""});
    place(12, 4);
    c.x = -200;
    c.y = 480;
    setCoordImg(c);
    setTermpic(str);
}

void ArcadeTitle::update()
{
}

ArcadeTitle::~ArcadeTitle()
{
}
