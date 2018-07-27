/*
** EPITECH PROJECT, 2018
** Arcade - Qix
** File description:
** Qix
*/

#ifndef Qix_HPP_
	#define Qix_HPP_

#include "IGame.hpp"
#include "BackgroundProcess.hpp"

class Qix : public IGame {
public:
		Qix();
		~Qix();
		void update();
		void init(Data *data);
protected:
};

#endif /* !Qix_HPP_ */
