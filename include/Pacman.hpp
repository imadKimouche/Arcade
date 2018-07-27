/*
** EPITECH PROJECT, 2018
** Arcade - Pacman
** File description:
** PacMan
*/

#ifndef PACMAN_HPP_
	#define PACMAN_HPP_

class Pacman;
#include "AObject.hpp"
#include "PacBoard.hpp"
#include "PacGame.hpp"
#include "Block.hpp"
#include <fstream>

class Pacman : public AObject{
public:
		Pacman(Data *data, PacBoard *board, PacGame *game);
		~Pacman();
		void update();
		bool moveValid(const int &x, const int &y);
		void look();
		void saveScore();
		void eat();
		void kill();
		bool isSuper() const;
		void move();
protected:
		int _life;
		bool _super;
		char _direction;
		char _directionW;
		PacGame *_game;
		PacBoard *_board;
};

#endif /* !PACMAN_HPP_ */
