//
// EPITECH PROJECT, 2018
// arcade
// File description:
// GUI for ncurses lib
//

#include "GuiNcurses.hpp"
#include <iostream>

GuiNcurses::GuiNcurses()
{
}

GuiNcurses::~GuiNcurses()
{
	wclear(_screen);
	delwin(_screen);
	clear();
	endwin();
}

short GuiNcurses::translateKey(void *key) const
{
	int *k = (int *)key;
	switch (*k)
	{
	case 10:
		_data->pushKey(M_KEY_ENTER);
		break;
	case KEY_UP:
		_data->pushKey(M_KEY_UP);
		break;
	case KEY_DOWN:
		_data->pushKey(M_KEY_DOWN);
		break;
	case KEY_LEFT:
		_data->pushKey(M_KEY_LEFT);
		break;
	case KEY_RIGHT:
		_data->pushKey(M_KEY_RIGHT);
		break;
	case 27:
		_data->pushKey(M_KEY_ESC);
		_data->setStop(true);
		break;
	case 'p':
		_data->pushKey(M_KEY_P);
		break;
	case 'o':
		_data->pushKey(M_KEY_O);
		break;
	case 'n':
		_data->pushKey(M_KEY_N);
		break;
	case 'b':
		_data->pushKey(M_KEY_B);
		break;
	case 'r':
		_data->pushKey(M_KEY_R);
		break;
  case 32:
      _data->pushKey(M_KEY_SPACE);
  	break;
  default:
		return 0;
	}
	return 0;
}

int GuiNcurses::txtHandler(IObject *o)
{
	int ch;

	while ((ch = getch()) != ERR)
	{
		switch (ch)
		{
		case KEY_BACKSPACE:
			if (o->getTermpic().size() >= 1)
				o->setTermpic(o->getTermpic().substr(0, o->getTermpic().size() - 1));
			break;
		case 27:
		case ' ':
		case 10:
			return 0;
		default:
			if (((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57)) && o->getTermpic().size() + 1 < TXT_HANDLER_SIZE)
				o->setTermpic(o->getTermpic() + (char)ch);
			break;
		}
	}
	return 1;
}

void GuiNcurses::keyHandler()
{
	int ch;

	for (short i = 1; i <= M_KEY_SPACE; i *= 2)
	{
		if (_data->isKey(i))
			_data->releaseKey(i);
	}
	while ((ch = getch()) != ERR)
	{
		translateKey(&ch);
	}
}

void GuiNcurses::update()
{
	int x = 0;
	int y = 0;
	int h = 0;
	int w = 0;

	getmaxyx(stdscr, h, w);
	if ((_fh != h || _fw != w) && (h - _data->getMapY()) / 2 - 1 > 0 && (w - _data->getMapX()) / 2 - 2 > 0)
	{
		erase();
		mvwin(_screen, (h - _data->getMapY()) / 2 - 1, (w - _data->getMapX()) / 2 - 2);
		_fh = h;
		_fw = w;
	}
	werase(_screen);
	for (size_t i = 0; i < _data->getObjects()->size(); i++)
	{
		computePos(_data->getObjects()->at(i));
		x = _data->getObjects()->at(i)->getCoord().x + 2;
		y = _data->getObjects()->at(i)->getCoord().y + 2;
		wmove(_screen, y, x);
		if (!_data->getObjects()->at(i)->getTermpic().empty())
			write(_data->getObjects()->at(i), _data->getObjects()->at(i)->getTermpic().c_str());
	}
	box(_screen, 0, 0);
	wrefresh(_screen);
}

void GuiNcurses::write(const IObject *o, const char *txt) const
{
	int color = 0;

	if (has_colors()) {
		color = termColor(o);
		if (init_pair(1, color, COLOR_BLACK) != ERR) {
            //if (o->getFont().a < 255)
              //  wattron(_screen, COLOR_PAIR(1) | A_INVIS);
            //else
                wattron(_screen, COLOR_PAIR(1));
		}
	}
    wprintw(_screen, txt);
	if (has_colors())
		wattroff(_screen, COLOR_PAIR(1) | A_INVIS);
}

int GuiNcurses::termColor(const IObject *o) const
{
	int r = o->getFont().r;
	int g = o->getFont().g;
	int b = o->getFont().b;
	int color = COLOR_WHITE;

	if (r == g && r == b) {
		color = COLOR_WHITE;
		return color;
	}
	if (r > g && r > b){
		if (g < b)
			color = COLOR_YELLOW;
		else if (b > g)
			color = COLOR_MAGENTA;
		else
			color = COLOR_RED;
	}
	else if (g > b){
		if (r < b)
			color = COLOR_YELLOW;
		else if (b > r)
			color = COLOR_CYAN;
		else
			color = COLOR_GREEN;
	}
	else {
		if (r < g)
			color = COLOR_MAGENTA;
		else if (b > g)
			color = COLOR_CYAN;
		else
			color = COLOR_BLUE;
	}
	return color;
}

void GuiNcurses::start(Data *data)
{
	int h;
	int w;

	if (!data || data->getMapX() <= 0 || data->getMapY() <= 0)
		throw AException("GuiNcurses: Error data map informations");
	_data = data;
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0);
	getmaxyx(stdscr, h, w);
	_screen = newwin(data->getMapY() + 2, data->getMapX() + 4, (h - data->getMapY()) / 2 - 1, (w - data->getMapX()) / 2 - 2);
	box(_screen, 0, 0);
	_fw = w;
	_fh = h;
	_cellsize = 1;
	start_color();
	update();
}

void GuiNcurses::computePos(IObject *o)
{
	IObject::Coordonnes_t p;
	IObject::Coordonnes_t togo;
	p.x = o->getCoord().x;
	p.y = o->getCoord().y;
	togo.x = o->getTogo().x;
	togo.y = o->getTogo().y;

	if (p.x < togo.x)
		p.x += 1.0 / ANIME_FRAME;
	if (p.x > togo.x)
		p.x -= 1.0 / ANIME_FRAME;
	if (p.y < togo.y)
		p.y += 1.0 / ANIME_FRAME;
	if (p.y > togo.y)
		p.y -= 1.0 / ANIME_FRAME;
	o->setCoord(p);
	_time = clock();
}

extern "C" IGUI *make()
{
	return new GuiNcurses();
}

extern "C" void destroy(IGUI *gui)
{
	delete gui;
}
