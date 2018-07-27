//
// EPITECH PROJECT, 2018
// arcade
// File description:
// qix
//

#include "Qix.hpp"

Qix::Qix()
{

}

Qix::~Qix()
{
}

void Qix::update()
{

}

void Qix::init(Data *data)
{
  _data = data;
  _data->setMapX(30);
  _data->setMapY(16);
  _data->setScore(0);
  _data->setSpritesheetname("ressources/image/inprocess.png");
  BackgroundProcess *bp = new BackgroundProcess();
  _data->addObjects(bp);
}

extern "C" IGame *make()
{
    return new Qix();
}

extern "C" void destroy(IGame *game)
{
    delete game;
}
