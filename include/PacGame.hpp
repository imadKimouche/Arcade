/*
** EPITECH PROJECT, 2018
** Arcade - PacMan
** File description:
** PacGame.hpp
*/

#ifndef PACGAME_HPP_
	#define PACGAME_HPP_

class PacGame;
#include "Ghost.hpp"
#include "IObject.hpp"
#include "Pacman.hpp"
#include "PacBoard.hpp"
#include "IGame.hpp"
#include "Block.hpp"
#include "Score.hpp"
#include "Lives.hpp"
#include "LivesTxt.hpp"
#include "StartGame.hpp"
#include <vector>
#include <unistd.h>
#include "GameOver.hpp"
#include "GameWin.hpp"

class PacGame : public IGame {
public:
		PacGame();
		~PacGame();
    void init(Data *data);
		void update();
		void stop();
		void restart();
		Lives *getLives();
private:
        PacBoard *_board;
				Pacman *_pacman;
				Score *_score;
				Lives *_lives;
				StartGame *_startGame;
				bool _isOn;
				bool _loop;
				GameOver *_gameOver;
				GameWin *_gameWin;
				std::vector<Ghost*> _ghosts;
};

#endif /* !PACGAME_HPP_ */
