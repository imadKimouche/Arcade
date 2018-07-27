/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** currentPlayer
*/

#ifndef currentPlayer_HPP_
#define currentPlayer_HPP_

#include "AObject.hpp"

class currentPlayer : public AObject
{
  public:
    currentPlayer(const std::string &);
    ~currentPlayer();
    void setScore(std::string str);
    void update();

  protected:
  private:
};

#endif /* !currentPlayer_HPP_ */
