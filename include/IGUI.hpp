//
// EPITECH PROJECT, 2018
// arcade
// File description:
// interface for GUI lib
//

#ifndef IGUI_HPP_
#define IGUI_HPP_

#include "Data.hpp"

class IGUI {
public:
	virtual ~IGUI() {};
	virtual void start(Data *data) = 0;
	virtual void update() = 0;
	virtual void keyHandler() = 0;
	virtual int txtHandler(IObject *o) = 0;
protected:
    Data *_data;
    int _cellsize;
};

#endif /* !IGUI_HPP_ */
