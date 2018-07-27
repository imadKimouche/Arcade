/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Lives
*/

#include "Lives.hpp"

Lives::Lives(const std::string &str)
{
    Coordonnes_t c;

    setFont(PFont_t{255, 255, 255, 255, 32, "./fonts/ka1.ttf"});
    place(26, 30);
    c.x = 32;
    c.y = 4 * 32;
    setCoordImg(c);
    c.x = 64;
    c.y = 32;
    setSize(c);
    setTermpic(str);
}

Lives::~Lives()
{
}

void Lives::update()
{
}

void Lives::Lives::setLives()
{
    Coordonnes_t c;
    c.x = getSize().x;
    c.y = getSize().y;

    if (c.x > 0){
      c.x -= 32;
      setSize(c);
    }
}
