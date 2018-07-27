/*
** EPITECH PROJECT, 2018
** Block
** File description:
** Block
*/

#ifndef Block_HPP_
#define Block_HPP_

#include <string.h>
#include <iostream>

#include "AObject.hpp"

class Block : public AObject
{
public:
	enum TYPE {
		GUM,
		WALL,
		DOOR,
		BACKGROUND,
		SUPERGUM
	};
	Block(TYPE const &, int const &, int const &, Coordonnes_t &);  //!< ctor
	~Block() = default;  //!< dtor
	TYPE getType()const;
	void setType(TYPE const &type);
	void update();
private:
TYPE _type;

};

#endif /* !Block_HPP_ */
