//
// EPITECH PROJECT, 2018
// arcade
// File description:
// GUI for ncurses lib
//

#ifndef GuiNcurses_HPP_
#define GuiNcurses_HPP_

#include "Data.hpp"
#include "IGUI.hpp"
#include "AException.hpp"
#include <curses.h>

#define ANIME_FRAME 32
#define TXT_HANDLER_SIZE 20

class GuiNcurses : public IGUI {
public:
	GuiNcurses(); //!<ctor
	~GuiNcurses(); //!<dtor
	short translateKey(void *key) const; //!< translates the ncurses key to the common key
	void keyHandler();//!<handles the keyboard input
	int txtHandler(IObject *o); //!<handles the text input
	void update(); //!< displays every object in the data structur
	void computePos(IObject *o); //!< computes the new position of the IObject
	void start(Data *data);//!<launchs the display
	void write(const IObject *o, const char *txt) const; //!< display a text to screen
	int termColor(const IObject *o) const; //!<find the right ncurses color for the RGB given with the IObject
private:
	WINDOW *_screen; /*!< the program screen*/
	clock_t _time;
	int _fw; /*!< *the screen width*/
	int _fh;  /*!< the screen height*/
};

#endif /* !GUISDL_HPP_ */
