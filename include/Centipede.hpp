/*
** EPITECH PROJECT, 2018
** Arcade - Centipede
** File description:
** Centipede
*/

#ifndef Centipede_HPP_
	#define Centipede_HPP_

	#include "IGame.hpp"
	#include "BackgroundProcess.hpp"

class Centipede : public IGame {
public:
		Centipede();
		~Centipede();
		void update();
		void init(Data *data);
protected:
};

#endif /* !Centipede_HPP_ */
