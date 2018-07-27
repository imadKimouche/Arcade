//
// EPITECH PROJECT, 2018
// arcade
// File description:
// GUI for SDL lib
//

#ifndef GUISDL_HPP_
#define GUISDL_HPP_

#include "Data.hpp"
#include "IGUI.hpp"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "AException.hpp"
#include <SDL/SDL_ttf.h>

#define ANIME_FRAME 8
#define TXT_HANDER_SIZE 20

class GUISDL : public IGUI {
public:
	GUISDL();//!< ctor
	~GUISDL();//!< dtor
	short translateKey(void *key) const; //!< translates the SDL key value to the common key value
	void keyHandler(); //!< handles the input key
	int txtHandler(IObject *o); //!< handles the input text
	void update(); //!< display the IObjects to the screen
	void start(Data *data); //!< starts the main program
	void computePos(IObject *o); //!< computes the new IObject position
	void printText(IObject *, SDL_Rect &pos); //!< prints the text value to the screen
private:
	SDL_Surface *_spritesheet; /*!< SDL surface of the sprite sheet */
	SDL_Surface *_screen; /*!< SDL surface of the main screen */
    clock_t _time;
};

#endif /* !GUISDL_HPP_ */
