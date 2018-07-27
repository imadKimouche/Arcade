//
// EPITECH PROJECT, 2018
// arcade
// File description:
//
// Data class header file
//

#ifndef DATA_HPP_
#define DATA_HPP_

#include <string>
#include <vector>
#include <algorithm>
class Data;
#include "IObject.hpp"

#define M_KEY_UP 1
#define M_KEY_DOWN 2
#define M_KEY_LEFT 4
#define M_KEY_RIGHT 8
#define M_KEY_ESC 16
#define M_KEY_ENTER 32
#define M_KEY_P 64
#define M_KEY_O 128
#define M_KEY_N 256
#define M_KEY_B 512
#define M_KEY_R 1024
#define M_KEY_SPACE 2048

class Data {
public:
	void setStop(const bool &stop); //!<sets the main loop boolean to true
	bool isStop() const; //!<tells if the main loop nees to stop
	void pushKey(const short &masque); //!<add the pushed key to the key handling variable
	void releaseKey(const short &masque);//!< removes the released key from the key handling variable
	bool isKey(const short &masque) const; //!<tells if the key was pressed
	void addObjects(IObject *object); //!< adds an IObject to the list of IObjects in order to display them
	std::vector<IObject*> *getObjects();//!< returns the set of IObject
    int getMapX() const; //!<returns the width value of the screen
	void setMapX(const int &v);//!<sets the width value of the screen
	int getMapY() const; //!< returns the height value of the screen
	void setMapY(const int &v);//!<return the hight value of the screen
	std::string getSpritesheetname() const; //!<returns the name of the sprite sheet
	void setSpritesheetname(const std::string &name);//!<sets the name of the sprite sheet
	int getScore() const;//!< returns the score of the current game
	void setScore(const int &s);//!< sets the score of the current game
private:
	std::vector<IObject*> _objects; /*!< set of IObject*/
	std::string _spritesheetname; /*!< name of the sprite sheet*/
	short _key; /*!< stores the key value*/
	int _mapX;/*!< width of the screen*/
	int _mapY; /*!< height of the screen*/
	int _score; /*!< score of the actual game*/
	bool _stop; /*!< boolean handling the main loop*/
};

#endif /* !DATA_HPP_ */
