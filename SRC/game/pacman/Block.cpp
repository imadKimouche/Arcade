//
// EPITECH PROJECT, 2018
// Block
// File description:
// Block class
//

#include "Block.hpp"

Block::Block(TYPE const & type, int const &x, int const &y, Coordonnes_t &c)
{
	_type = type;
	place(x, y);
	setCoordImg(c);
	setSize({32, 32});
	setSolid(false);
	switch(type){
		case GUM:
				setFont(PFont_t{255, 216, 0, 255, 25, "./fonts/ka1.ttf"});
				setTermpic("o");
		break;
		case WALL:
				setFont(PFont_t{0, 2, 147, 255, 25, "./fonts/ka1.ttf"});
				setTermpic("X");
				setSolid(true);
		break;
		case BACKGROUND:
				setFont(PFont_t{0, 0, 0, 255, 25, "./fonts/ka1.ttf"});
				setTermpic(" ");
		break;
		case SUPERGUM:
				setFont(PFont_t{255, 216, 0, 255, 25, "./fonts/ka1.ttf"});
				setTermpic("O");
		break;
		default:
		break;
	}
}

Block::TYPE Block::getType()const
{
	return _type;
}

void Block::setType(TYPE const &type)
{
	if (_type == GUM && type == BACKGROUND) {
		setCoordImg(Coordonnes_t{400, 400});
		setTermpic(" ");
	}
	_type = type;
}

void Block::update()
{

}
