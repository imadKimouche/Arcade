//
// Created by tony on 29/03/18.
//

#include "Background.hpp"
#include <iostream>

Background::Background()
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

void Background::update()
{
}