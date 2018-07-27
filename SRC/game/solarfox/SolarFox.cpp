//
// EPITECH PROJECT, 2018
// arcade
// File description:
// solarFox
//

#include "SolarFox.hpp"

SolarFox::SolarFox()
{
}

SolarFox::~SolarFox()
{
}

void SolarFox::update()
{

}

void SolarFox::init(Data *data)
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
    return new SolarFox();
}

extern "C" void destroy(IGame *game)
{
    delete game;
}
