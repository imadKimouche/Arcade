/*
** EPITECH PROJECT, 2018
** Arcade - Pacman
** File description:
** Ghost.hpp
*/

#ifndef GHOST_HPP_
	#define GHOST_HPP_

class Ghost;
#include "AObject.hpp"
#include "Pacman.hpp"
#include "PacBoard.hpp"
#include "PacGame.hpp"
#include "Block.hpp"
#include <stdlib.h>

class Ghost : public AObject {
public:
		enum IA {
			RANDOM,
			HUNT,
			ESCAPE,
			WAIT
		};
		Ghost(const int &n, Data *data, PacBoard *board, Pacman *pacman);
		~Ghost();
		void update();
		bool move();
		void mindRand();
		bool moveValid(const int &x, const int &y);
		void eat();
		void setDepart(const Coordonnes_t &c);
		void reset();
protected:
		Pacman *_pacman;
		PacBoard *_board;
    char _direction;
		IA _mind;
		Coordonnes_t _depart;
		std::vector<IObject::Coordonnes_t> _path;
};

#endif /* !GHOST_HPP_ */
