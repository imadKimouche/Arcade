/*
** EPITECH PROJECT, 2018
** Arcade - SolarFox
** File description:
** SolarFox
*/

#ifndef SolarFox_HPP_
	#define SolarFox_HPP_

	#include "IGame.hpp"
	#include "BackgroundProcess.hpp"

class SolarFox : public IGame {
public:
		SolarFox();
		~SolarFox();
		void update();
		void init(Data *data);
protected:
};

#endif /* !SolarFox_HPP_ */
