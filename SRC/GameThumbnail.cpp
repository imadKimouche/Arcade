/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** game thumbnail
*/

#include "GameThumbnail.hpp"

GameThumbnail::GameThumbnail()
{
    Coordonnes_t c;
    place(14, 8);
    c.x = 1280;
    c.y = 0;
    setCoordImg(c);
    c.x = 300;
    c.y = 200;
    setSize(c);
}

GameThumbnail::~GameThumbnail()
{
}

void GameThumbnail::update()
{
}