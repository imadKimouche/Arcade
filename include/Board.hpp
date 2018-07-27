/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** Board.hpp
*/

#ifndef BOARD_HPP_
	#define BOARD_HPP_

class Board : public AObject {
	public:
		Board(SnakeGame *game);   //!< ctor
		~Board() = default;   //!< dtor
		void update();   //!< updates the state of the board
		bool isLegal(int x, int y);   //!< checks if a coordiante is in the frame
		int getFood(int x, int y);   //!< picks up the fruit on the board, sets the new size of the snake
		int getX();  //!< returns the X value
		int getY();  //!< returns the Y value
		void init();   //!< sets initializing values of the board
	protected:
		SnakeGame *game; /*!< a pointerr to the game*/
		double size_x; /*!<  x value of the map*/
		double size_y; /*!<  y value of the map*/
		Food *food; /*!< pointer to food */
};

#endif /* !BOARD_HPP_ */
