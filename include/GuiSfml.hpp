//
// EPITECH PROJECT, 2018
// arcade
// File description:
// GUI for sfml lib
//

#ifndef GuiSfml_HPP_
#define GuiSfml_HPP_

#include "Data.hpp"
#include "IGUI.hpp"
#include "AException.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define ANIME_FRAME 8
#define TXT_HANDER_SIZE 20

class GuiSfml : public IGUI {
public:
	GuiSfml();//!< ctor
	~GuiSfml();//!< dtor
	short translateKey(sf::Keyboard::Key &key) const; //!< translate the ncurses keys to the common key value
	void keyHandler(); //!< handles the input key
	int txtHandler(IObject *o); //!<handles the text input
	void update(); //!< displays the IObject to the screen
	void start(Data *data); //!< starts the main program
	void computePos(IObject *o); //!< computes the new IObject's position
	void printText(IObject *, const sf::Vector2f &pos); //!< prints the text value to the screen
private:
	sf::Texture _spritesheet; /*!<  ncurses thecture of the sprite sheet*/
	sf::RenderWindow _screen; /*!< ncurses render screen */
    clock_t _time;
};

#endif /* !GuiSfml_HPP_ */
