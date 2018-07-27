/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Lives
*/

#ifndef Lives_HPP_
#define Lives_HPP_

class Lives;
#include "AObject.hpp"
#include <string>

class Lives : public AObject
{
  public:
    Lives(const std::string &);
    ~Lives();
    void setLives();
    void update();

  protected:
  private:
};

#endif /* !Lives_HPP_ */
