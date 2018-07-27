//
// EPITECH PROJECT, 2018
// arcade
// File description:
// GUI for SDL lib
//

#include "GUISDL.hpp"
#include <iostream>

GUISDL::GUISDL()
{
}

GUISDL::~GUISDL()
{
	if (_spritesheet)
		SDL_FreeSurface(_spritesheet);
	if (_screen)
		SDL_FreeSurface(_screen);
	TTF_Quit();
	SDL_Quit();
}

short GUISDL::translateKey(void *key) const
{
	SDLKey *k = (SDLKey *)key;
	switch (*k)
	{
	case SDLK_LEFT:
		return M_KEY_LEFT;
	case SDLK_RIGHT:
		return M_KEY_RIGHT;
	case SDLK_UP:
		return M_KEY_UP;
	case SDLK_DOWN:
		return M_KEY_DOWN;
	case SDLK_ESCAPE:
		_data->setStop(true);
		return M_KEY_ESC;
	case SDLK_RETURN:
		return M_KEY_ENTER;
	case SDLK_p:
		return M_KEY_P;
	case SDLK_o:
		return M_KEY_O;
	case SDLK_n:
		return M_KEY_N;
	case SDLK_b:
		return M_KEY_B;
	case SDLK_r:
		return M_KEY_R;
	case SDLK_SPACE:
		return M_KEY_SPACE;
	default:
		return 0;
	}
}

int GUISDL::txtHandler(IObject *o)
{
	SDL_Event event;

	SDL_PollEvent(&event);
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_BACKSPACE:
			if (o->getTermpic().size() >= 1)
				o->setTermpic(o->getTermpic().substr(0, o->getTermpic().size() - 1));
			break;
		case SDLK_SPACE:
		case SDLK_RETURN:
		case SDLK_ESCAPE:
			return 0;
		default:
			if (SDL_GetKeyName(event.key.keysym.sym)[1] == '\0' && o->getTermpic().size() + 1 < TXT_HANDER_SIZE)
				o->setTermpic(o->getTermpic() + SDL_GetKeyName(event.key.keysym.sym));
			break;
		}
	}
	else if (event.type == SDL_QUIT)
		_data->setStop(true);
	return 1;
}

void GUISDL::keyHandler()
{
	SDL_Event event;
	SDLKey *tmp;

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_KEYDOWN:
		tmp = &event.key.keysym.sym;
		_data->pushKey(translateKey((void *)tmp));
		break;
	case SDL_KEYUP:
		tmp = &event.key.keysym.sym;
		_data->releaseKey(translateKey((void *)tmp));
		break;
	case SDL_QUIT:
		_data->setStop(true);
		break;
	}
}

void GUISDL::update()
{
	SDL_Rect pos;
	SDL_Rect pic;

	SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 0, 0, 0));
	if (!_spritesheet)
		return;
	for (unsigned int i = 0; i < _data->getObjects()->size(); i++)
	{
		pic.x = _data->getObjects()->at(i)->getCoordImg().x;
		pic.y = _data->getObjects()->at(i)->getCoordImg().y;
		pic.w = _data->getObjects()->at(i)->getSize().x;
		pic.h = _data->getObjects()->at(i)->getSize().y;
		computePos(_data->getObjects()->at(i));
		pos.x = _data->getObjects()->at(i)->getCoord().x * _cellsize;
		pos.y = _data->getObjects()->at(i)->getCoord().y * _cellsize;
		if (pic.x >= 0 && pic.y >= 0)
			SDL_BlitSurface(_spritesheet, &pic, _screen, &pos);
		else
			printText(_data->getObjects()->at(i), pos);
	}
	SDL_Flip(_screen);
}

void GUISDL::start(Data *data)
{
	if (!data || data->getMapX() <= 0 || data->getMapY() <= 0)
		throw AException("GUISDL: Error data map informations");
	_data = data;
	_spritesheet = IMG_Load(_data->getSpritesheetname().c_str());
	if (!_spritesheet)
		throw AException("GUISDL: spritesheet not found");
	if (SDL_Init(SDL_INIT_VIDEO) == -1 || TTF_Init() == -1)
		throw AException("GUISDL: Error SDL or TTF init");
	_cellsize = 32;
	_screen = SDL_SetVideoMode(_data->getMapX() * _cellsize,
							   _data->getMapY() * _cellsize, 32, SDL_HWSURFACE);
	if (!_screen)
		throw AException("GUISDL: Error SDL videoMode");
	update();
}

void GUISDL::printText(IObject *o, SDL_Rect &pos)
{
	TTF_Font *font = NULL;
	SDL_Surface *txt = NULL;
	SDL_Color color = {0, 0, 0, 0};
	int size = 32;

	if (o->getTermpic().empty())
		return;
	if (o->getFont().size > 4 && o->getFont().size < 300)
		size = o->getFont().size;
	if (!o->getFont().font.empty())
		font = TTF_OpenFont(o->getFont().font.c_str(), size);
	color = {o->getFont().r, o->getFont().g, o->getFont().b, o->getFont().a};
	if (!font)
		font = TTF_OpenFont("fonts/default.ttf", size);
	if (!font)
		return;
	txt = TTF_RenderText_Blended(font, o->getTermpic().c_str(), color);
	if (!txt)
		return;
	SDL_BlitSurface(txt, NULL, _screen, &pos);
	TTF_CloseFont(font);
	SDL_FreeSurface(txt);
}

void GUISDL::computePos(IObject *o)
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
	return new GUISDL();
}

extern "C" void destroy(IGUI *gui)
{
	delete gui;
}
