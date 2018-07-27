/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score
*/

#include "Score.hpp"

Score::Score(const std::string &str)
{
    Coordonnes_t c;

    setFont(PFont_t{255, 200, 0, 255, 18, "./fonts/ka1.ttf"});
    place(1, 2);
    c.x = -200;
    setCoordImg(c);
    c.x = 35;
    setSize(c);
    setTermpic(str);
}

Score::~Score()
{
}

void Score::update()
{
}

void Score::Score::setScore(std::string str)
{
    setTermpic(str);
}
