// EPITECH PROJECT, 2018
// arcade
// File description:
// Data class
//

#include "Data.hpp"

void Data::setStop(const bool &stop)
{
	_stop = stop;
}

bool Data::isStop() const
{
	return _stop;
}

void Data::pushKey(const short &masque)
{
	if (!isKey(masque))
		_key = _key | masque;
}

void Data::releaseKey(const short &masque)
{
	if (isKey(masque))
		_key = _key ^ masque;
}

bool Data::isKey(const short &masque) const
{
	return _key & masque;
}

void Data::addObjects(IObject *object)
{
	if (std::find(_objects.begin(), _objects.end(), object) == _objects.end())
    	_objects.push_back(object);
}

std::vector<IObject*> *Data::getObjects()
{
	return &_objects;
}

int Data::getMapX() const
{
	return _mapX;
}

void Data::setMapX(const int &v)
{
	_mapX = v;
}

int Data::getMapY() const
{
	return _mapY;
}

void Data::setMapY(const int &v)
{
	_mapY = v;
}

std::string Data::getSpritesheetname() const
{
	return _spritesheetname;
}

void Data::setSpritesheetname(const std::string &name)
{
	_spritesheetname = name;
}

int Data::getScore() const
{
	return _score;
}

void Data::setScore(const int &s)
{
	_score = s;
}
