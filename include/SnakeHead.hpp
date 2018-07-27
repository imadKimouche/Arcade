/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** SnakeHead.pp
*/

#ifndef SNAKEHEAD_HPP_
	#define SNAKEHEAD_HPP_

class SnakeHead : public AObject {
        const Coordonnes_t sizeH = {32, 32};
        const Coordonnes_t SHeadUP = {3 * 32, 0 * 32};
        const Coordonnes_t SHeadDOWN = {4 * 32, 1 * 32};
        const Coordonnes_t SHeadLEFT = {3 * 32, 1 * 32};
        const Coordonnes_t SHeadRIGHT = {4 * 32, 0 * 32};
	public:
	SnakeHead(SnakeGame *game);
	~SnakeHead() = default;
        void move();
        void update();
        void change_face(char direction);
        SnakeGame *getGame();
        void eat(int value);
        bool isHere(int x, int y);
        bool moveFinished();
	protected:
        SnakeGame *game;
        SnakeBody *first;
        char front;
        char behind;
        double x;
        double y;
};

#endif /* !SNAKEHEAD_HPP_ */
