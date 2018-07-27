/*
** EPITECH PROJECT, 2018
** arcade 
** File description:
** player name
*/

#ifndef PLAYERNAME_HPP_
#define PLAYERNAME_HPP_

#include "AObject.hpp"

class PlayerName : public AObject
{
  public:
	PlayerName(const std::string &);
	~PlayerName();

	void update();

  protected:
  private:
};

#endif /* !PLAYERNAME_HPP_ */
