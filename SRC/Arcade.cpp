//
// EPITECH PROJECT, 2018
// arcade
// File description:
// arcade class
//

#include "Arcade.hpp"

Arcade::Arcade()
{
}

void Arcade::start(int ac, char **av)
{
	checkParams(ac, av);

	_mainGui = new MainGui(av[1]);
	_mainGui->run();
}

void Arcade::checkParams(int ac, char **av) const
{
	std::string help("--help");
	std::string Help("--Help");

	if (ac != 2)
	{
		std::cerr << "Wrong parameters, use --Help for help" << std::endl;
		exit(84);
	}
	if (!help.compare(av[1]) || !Help.compare(av[1]))
	{
		std::cerr << "USAGE\n\t./arcade ./[dynamic lib]" << std::endl;
		exit(0);
	}
}
