//
// EPITECH PROJECT, 2018
// aracde
// File description:
// IGame class header
//

#ifndef IGAME_HPP_
        #define IGAME_HPP_

#include "IObject.hpp"
#include "Data.hpp"

class IGame {
public:
	virtual void init(Data *data) = 0;
	virtual ~IGame() {};
	virtual void update() = 0;
protected:
	Data *_data;
};

#endif /* !IGAME_HPP_ */
