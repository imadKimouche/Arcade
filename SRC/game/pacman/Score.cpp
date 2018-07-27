/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score
*/

#include "Score.hpp"

#include <iostream>

Score::Score(const std::string &str)
{
    Coordonnes_t c;
    setFont(PFont_t{255, 255, 255, 255, 32, "./fonts/ka1.ttf"});
    place(0, 30);
    c.x = -200;
    setCoordImg(c);
    c.x = 35;
    setSize(c);

    setTermpic("SCORE " + str);
}

Score::~Score()
{
}

void Score::update()
{
}

void Score::Score::setScore(std::string str)
{
  setTermpic("SCORE " + str);
}
