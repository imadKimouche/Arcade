/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** arcade title
*/

#ifndef ARCADETITLE_HPP_
#define ARCADETITLE_HPP_

#include "AObject.hpp"
#include <unistd.h>

class ArcadeTitle : public AObject
{
  public:
	ArcadeTitle(const std::string &);   //!< ctor
	~ArcadeTitle();   //!< dtor

	void update();

  protected:
  private:
};

#endif /* !GAMETITLE_HPP_ */
