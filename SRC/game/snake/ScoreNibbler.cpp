/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Score
*/

#include "ScoreNibbler.hpp"

ScoreNibbler::ScoreNibbler(std::string str)
{
    Coordonnes_t c;

    setFont(PFont_t{255, 0, 0, 255, 25, "./fonts/ka1.ttf"});
    place(20, 20);
    c.x = -200;
    setCoordImg(c);
    c.x = 35;
    setSize(c);
    setTermpic(str);
}

ScoreNibbler::~ScoreNibbler()
{
}

void ScoreNibbler::update()
{
}

void ScoreNibbler::ScoreNibbler::setScore(std::string str)
{
    setTermpic(str);
}