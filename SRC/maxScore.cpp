/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** maxScore
*/

#include "maxScore.hpp"

#include <iostream>

maxScore::maxScore(const std::string &str)
{
    Coordonnes_t c;

    setFont(PFont_t{255, 200, 0, 255, 20, "./fonts/ka1.ttf"});
    place(1, 1);
    c.x = -200;
    setCoordImg(c);
    c.x = 35;
    setSize(c);
    setTermpic(str);
}

maxScore::~maxScore()
{
}

void maxScore::update()
{
}

void maxScore::maxScore::setScore(std::string str)
{
    setTermpic(str);
}
