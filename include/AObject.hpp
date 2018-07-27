//
// EPITECH PROJECT, 2018
// arcade
// File description:
// Object class header
//

#ifndef AOBJECT_HPP_
#define AOBJECT_HPP_

#include "IObject.hpp"

class AObject : public IObject {
public:
	AObject();   //!< ctor
	AObject(const Coordonnes_t &c);   //!< ctor
	AObject(const Coordonnes_t &co, const Coordonnes_t &ci, const std::string &c);   //!< ctor
	virtual ~AObject() {};
	virtual void update() = 0;   //!< main loop of the execution, updates the data structure each frame
	Coordonnes_t getCoord() const;   //!< gives the actual position of the object
	Coordonnes_t getCoordImg() const;   //!< gives the postion of the wanted sprite on sprite sheet
	std::string getTermpic() const;    //!< return the textual value of the IObject
	Coordonnes_t getSize() const;   //!< returns the size of the IObject
	Coordonnes_t getTogo() const;   //!< returns the position to where IObject is heading
	PFont_t getFont() const;   //!< returns the font of the string in the IObject
	void setFont(PFont_t font);   //!< sets the font of the string of the IObject
	void place (const int &x, const int &y);   //!<  places the IObject at the given position
	void go(const Coordonnes_t &coord);   //!< tells a IObject to move to a position
	void setCoord(const Coordonnes_t &coord);  //!< sets the position of the IObject
	void setCoordImg(const Coordonnes_t &coord);  //!< sets the position of the sprite in the spritesheet
	void setTermpic(const std::string &term);  //!< sets the textual value of the IObject
	void setSize(const Coordonnes_t &t);   //!< sets the siez of the IObjetc
	bool isSolid() const; //!< return true if the object is solid
	void setSolid(const bool &solid); //!< set the colision with the Object
private:
	bool _solid;
};

#endif /* !OBJECT_HPP_  */
