/*
** EPITECH PROJECT, 2018
** Arcade - Pacman
** File description:
** PacmanPlayer.hpp
*/

#ifndef PACMANPLAYER_HPP_
	#define PACMANPLAYER_HPP_

class PacmanPlayer : public AObject {
	public:
		PacmanPlayer();
		~PacmanPlayer();
        void move();
        void update();
        void look(char dir);
        bool moveDone();
	protected:
    PacGame *game;
    char face;
};

#endif /* !PACMANPLAYER_HPP_ */
