/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** currentPlayer
*/

#include "currentPlayer.hpp"

#include <iostream>

currentPlayer::currentPlayer(const std::string &str)
{
    Coordonnes_t c;

    setFont(PFont_t{255, 200, 0, 255, 20, "./fonts/ka1.ttf"});
    place(24, 1);
    c.x = -200;
    setCoordImg(c);
    c.x = 35;
    setSize(c);
    setTermpic(str);
}

currentPlayer::~currentPlayer()
{
}

void currentPlayer::update()
{
}

void currentPlayer::setScore(std::string str)
{
    setTermpic(str);
}
