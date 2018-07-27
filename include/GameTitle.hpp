/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** game title
*/

#ifndef GAMETITLE_HPP_
#define GAMETITLE_HPP_

#include "AObject.hpp"

class GameTitle : public AObject
{
  public:
    GameTitle(const std::string &); //!<ctor
    ~GameTitle(); //!<dtor

    void update();

  protected:
  private:
};

#endif /* !GAMETITLE_HPP_ */
