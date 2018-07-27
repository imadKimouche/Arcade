/*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** Food.hpp
*/

#ifndef FOOD_HPP_
	#define FOOD_HPP_

class Food : public AObject {
    const Coordonnes_t sizeF = {32, 32};
    const Coordonnes_t SFood = {0, 3 * 32};
	const Coordonnes_t SFoodG = {32 * 1, 3 * 32};
	public:
		Food(SnakeGame *game); //!< ctor
		~Food() = default; //!<dtor
		void update(); 
		bool isIn(int x, int y);  //!< tells if the food is on the given postion or not
		int getValue(); //!<returns the value of growth
		void reload(); //!< reloads and places the food in a new place
	protected:
		int x; /*!< horizontal position of the food*/
		int y; /*!< *vertical position of the food*/
		int type; /*!< if it's golden or not*/
		int scoreValue; /*!< value of each food when eaten*/
		int growValue; /*!< number of segments the snake grown when eating*/
		SnakeGame *game; /*!< pointer to game*/
};

#endif /* !FOOD_HPP_ */
