/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** down left wall
*/

#ifndef gum_HPP_
#define gum_HPP_

#include "AObject.hpp"

class gum : public AObject
{
  public:
    gum(int, int);
    ~gum();

    void update();

  protected:
  private:
};

#endif /* !gum_HPP_ */
