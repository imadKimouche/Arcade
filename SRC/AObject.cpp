//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Game objects class
//

#include "AObject.hpp"

AObject::AObject()
{
}

AObject::AObject(const Coordonnes_t &c)
{
	setCoord(c);
}

AObject::AObject(const Coordonnes_t &co, const Coordonnes_t &ci, const std::string &c)
{
	setCoord(co);
	setCoordImg(ci);
	setTermpic(c);
}

IObject::Coordonnes_t AObject::getCoord() const
{
	return _coord;
}

IObject::Coordonnes_t AObject::getTogo() const
{
	return _togo;
}

IObject::Coordonnes_t AObject::getCoordImg() const
{
	return _imgCoord;
}

std::string AObject::getTermpic() const
{
	return _termpic;
}

IObject::Coordonnes_t AObject::getSize() const
{
	return _size;
}

void AObject::go(const Coordonnes_t &coord)
{
	_togo = coord;
}

void AObject::setCoord(const Coordonnes_t &coord)
{
	_coord = coord;
}

void AObject::setCoordImg(const Coordonnes_t &coord)
{
	_imgCoord = coord;
}

void AObject::setTermpic(const std::string &term)
{
	_termpic = term;
}

void AObject::setSize(const Coordonnes_t &t)
{
	_size = t;
}

void AObject::place(const int &x, const int &y)
{
	Coordonnes_t tmp;

	tmp.x = x;
	tmp.y = y;
	setCoord(tmp);
	go(tmp);
}

bool AObject::isSolid() const
{
	return _solid;
}

void AObject::setSolid(const bool &solid)
{
	_solid = solid;
}

AObject::PFont_t AObject::getFont() const
{
	return _font;
}

void AObject::setFont(PFont_t font)
{
	_font = font;
}
