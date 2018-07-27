/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** maxScore
*/

#ifndef MAXSCORE_HPP_
#define MAXSCORE_HPP_

#include "AObject.hpp"

class maxScore : public AObject
{
  public:
    maxScore(const std::string &);
    ~maxScore();
    void setScore(std::string str);
    void update();

  protected:
  private:
};

#endif /* !MAXSCORE_HPP_ */
