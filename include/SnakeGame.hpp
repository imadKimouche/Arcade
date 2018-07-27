/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** Game.hpp
*/

#ifndef GAME_HPP_
	#define GAME_HPP_

#include "Snake.hpp"
#include "GameOver.hpp"

class SnakeGame : public IGame {
	public:
		SnakeGame();
		~SnakeGame();
		void init(Data *data);
		Data *getData();
		void update();
		bool isLegal(int x, int y);
		void end();
		int getFood(int x, int y);
		void addScore(int value);
		bool isSnake(int x, int y);
		void changeScore();
		void addObjects(AObject *obj);
		int getScore() const;

	protected:
		GameOver *_gameOver;
		int state;
		int score;
		int speed;
		int tik_count;
		ScoreNibbler *points;
		SnakeHead *snake;
		Board *board;
};

#endif /* !GAME_HPP_ */
