//
// EPITECH PROJECT, 2018
// arcade
// File description:
// GUI for sfml lib
//

#include "GuiSfml.hpp"
#include <iostream>

GuiSfml::GuiSfml()
{
}

GuiSfml::~GuiSfml()
{
	_screen.close();
}

short GuiSfml::translateKey(sf::Keyboard::Key &key) const
{
	switch (key)
	{
	case sf::Keyboard::Left:
		return M_KEY_LEFT;
	case sf::Keyboard::Right:
		return M_KEY_RIGHT;
	case sf::Keyboard::Up:
		return M_KEY_UP;
	case sf::Keyboard::Down:
		return M_KEY_DOWN;
	case sf::Keyboard::Escape:
		_data->setStop(true);
		return M_KEY_ESC;
	case sf::Keyboard::Return:
		return M_KEY_ENTER;
	case sf::Keyboard::P:
		return M_KEY_P;
	case sf::Keyboard::O:
		return M_KEY_O;
	case sf::Keyboard::N:
		return M_KEY_N;
	case sf::Keyboard::B:
		return M_KEY_B;
	case sf::Keyboard::R:
		return M_KEY_R;
	case sf::Keyboard::Space:
		std::cout << "/* message */" << '\n';
		return M_KEY_SPACE;
	default:
		return 0;
	}
}

int GuiSfml::txtHandler(IObject *o)
{
	sf::Event event;
	char c = 0;

	_screen.pollEvent(event);
	if (event.type == sf::Event::Closed) {
		_data->setStop(true);
		return 0;
	} else if (event.type != sf::Event::KeyPressed)
		return 0;
	if (event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Return ||
			event.key.code == sf::Keyboard::Space)
		return 0;
	else if (event.key.code == sf::Keyboard::BackSpace && o->getTermpic().size() >= 1)
		o->setTermpic(o->getTermpic().substr(0, o->getTermpic().size() - 1));
	if (o->getTermpic().size() + 1 > TXT_HANDER_SIZE)
		return 1;
	if (event.key.code >= 0 && event.key.code <= 25)
		c = 97 + event.key.code;
	else if (event.key.code >= 26 && event.key.code <= 34)
		c = 48 + event.key.code;
	if (c != 0)
		o->setTermpic(o->getTermpic() + c);
	return 0;
}

void GuiSfml::keyHandler()
{
	sf::Event event;

	if (!_screen.isOpen())
		_screen.create(sf::VideoMode(_data->getMapX() * _cellsize, _data->getMapY() * _cellsize), "Arcade");
	while (_screen.pollEvent(event)) {
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				_data->pushKey(translateKey(event.key.code));
				break;
			case sf::Event::KeyReleased:
				_data->releaseKey(translateKey(event.key.code));
				break;
			case sf::Event::Closed:
				_data->setStop(true);
				break;
			default:
				break;
		}
	}
}

void GuiSfml::update()
{
	int x = 0;
	int y = 0;
	sf::Sprite sprite;
	sf::Vector2f pos;

	_screen.clear();
	for (unsigned int i = 0; i < _data->getObjects()->size(); i++)
	{
		x = _data->getObjects()->at(i)->getCoordImg().x;
		y = _data->getObjects()->at(i)->getCoordImg().y;
		pos.x = _data->getObjects()->at(i)->getCoord().x * _cellsize;
		pos.y = _data->getObjects()->at(i)->getCoord().y * _cellsize;
		computePos(_data->getObjects()->at(i));
		if (x >= 0 && y >= 0) {
			sprite.setTexture(_spritesheet);
			sprite.setTextureRect(sf::IntRect(x, y, _data->getObjects()->at(i)->getSize().x, _data->getObjects()->at(i)->getSize().y));
			sprite.setPosition(pos);
			_screen.draw(sprite);
		} else
			printText(_data->getObjects()->at(i), pos);
	}
	_screen.display();
}

void GuiSfml::start(Data *data)
{
	if (!data || data->getMapX() <= 0 || data->getMapY() <= 0)
		throw AException("GuiSfml: Error data map informations");
	_data = data;
	if (!data->getSpritesheetname().empty() && !_spritesheet.loadFromFile(data->getSpritesheetname()))
		throw AException("GuiSfml: spritesheet not found");
	_cellsize = 32;
	sf::err().rdbuf(NULL);
}

void GuiSfml::printText(IObject *o, const sf::Vector2f &pos)
{
	sf::Font font;
	sf::Text text;
	int size = 32;

	if (o->getTermpic().empty())
		return;
	if (o->getFont().size > 4 && o->getFont().size < 300)
		size = o->getFont().size;
	if (!o->getFont().font.empty()) {
		if (!font.loadFromFile(o->getFont().font)) {
			if (!font.loadFromFile("./fonts/default.ttf"))
				return;
		}
	} else if (!font.loadFromFile("./fonts/default.ttf"))
		return;
	text.setFont(font);
	text.setString(o->getTermpic().c_str());
	text.setCharacterSize(size);
	text.setColor(sf::Color(o->getFont().r, o->getFont().g, o->getFont().b, o->getFont().a));
	text.setPosition(pos);
	_screen.draw(text);
}

void GuiSfml::computePos(IObject *o)
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
	return new GuiSfml();
}

extern "C" void destroy(IGUI *gui)
{
	delete gui;
}
