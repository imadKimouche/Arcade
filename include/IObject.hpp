// EPITECH PROJECT, 2018
// arcade
// File description:
// Object class interface
//

#ifndef IOBJECT_HPP_
#define IOBJECT_HPP_

#include <string>
class IObject;
#include "Data.hpp"

class IObject {
public:
	typedef struct {
		double x;
		double y;
	} Coordonnes_t;
	typedef struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
		int size;
		std::string font;
	} PFont_t;
	virtual ~IObject() {};
	virtual void update() = 0;
	virtual Coordonnes_t getCoord() const = 0;
	virtual Coordonnes_t getTogo() const = 0;
	virtual Coordonnes_t getCoordImg() const = 0;
	virtual std::string getTermpic() const = 0;
	virtual Coordonnes_t getSize() const = 0;
	virtual PFont_t getFont() const = 0;
	virtual void setFont(PFont_t font) = 0;
	virtual void setCoord(const Coordonnes_t &coord) = 0;
	virtual void place(const int &x, const int &y) = 0;
	virtual void go(const Coordonnes_t &coord) = 0;
	virtual void setCoordImg(const Coordonnes_t &coord) = 0;
	virtual void setTermpic(const std::string &term) = 0;
	virtual void setSize(const Coordonnes_t &t) = 0;
protected:
	Data *_data;
	PFont_t _font;
	Coordonnes_t _coord;
	Coordonnes_t _togo;
	Coordonnes_t _imgCoord;
	std::string _termpic;
    Coordonnes_t _size;
};

#endif /* !IOBJECT_HPP_  */
