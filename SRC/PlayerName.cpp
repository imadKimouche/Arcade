/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** player name
*/

#include "PlayerName.hpp"

PlayerName::PlayerName(const std::string &str)
{
    Coordonnes_t c;

    setFont(PFont_t{255, 0, 0, 255, 20, ""});
    place(32, 1);
    c.x = -200;
    setCoordImg(c);

    setTermpic(str);
}

PlayerName::~PlayerName()
{
}

void PlayerName::update()
{
}
