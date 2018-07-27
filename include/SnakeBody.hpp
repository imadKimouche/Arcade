/*
** EPITECH PROJECT, 2018
** Snake - Arcade
** File description:
** SnakeBody.hpp
*/

#ifndef SNAKEBODY_HPP_
	#define SNAKEBODY_HPP_

class SnakeBody : public AObject {
        const Coordonnes_t sizeM = {32, 32};
        const Coordonnes_t SBodyUD = {32 * 2, 32 * 1};
        const Coordonnes_t SBodyLR = {32 * 1, 32 * 0};
        const Coordonnes_t SBodyDL = {32 * 2, 32 * 0};
        const Coordonnes_t SBodyLU = {32 * 2, 32 * 2};
        const Coordonnes_t SBodyUR = {32 * 0, 32 * 1};
        const Coordonnes_t SBodyRD = {32 * 0, 32 * 0};
        const Coordonnes_t SBodyUE = {32 * 3, 32 * 2};
        const Coordonnes_t SBodyRE = {32 * 4, 32 * 2};
        const Coordonnes_t SBodyDE = {32 * 4, 32 * 3};
        const Coordonnes_t SBodyLE = {32 * 3, 32 * 3};
	public:
	SnakeBody(SnakeHead *origin, int left, int x, int y);
    SnakeBody(SnakeHead *origin, char front, int x, int y);
	~SnakeBody() = default;
        void move(SnakeHead *head, int x, int y, char _front, char _behind);
        void grow(int size);
        void addgrowWait(int var);
        void update();
        void eat(int value);
        bool isHere(int x, int y);
        void autoSetSprite();
        void isFirst();
	protected:
        char front;
        char behind;
        bool first;
        SnakeBody *next;
        SnakeHead *head;
        SnakeGame *game;
        double x;
        double y;
        int growWait;
};

#endif /* !SNAKEBODY_HPP_ */
