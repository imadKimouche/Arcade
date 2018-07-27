/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** arcade class header
*/

#ifndef ARCADE_HPP_
#define ARCADE_HPP_

#include <string.h>
#include <iostream>

#include "MainGui.hpp"

class Arcade
{
public:
	Arcade();  //!< ctor
	~Arcade() = default;   //!< dtor
	void start(int ac, char **av);   //!< launches the main menu of arcade
	void checkParams(int ac, char **) const;   //!< checks the input parametres
private:
	MainGui *_mainGui;
};

#endif /* !ARCADE_HPP_ */
