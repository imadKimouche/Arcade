/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** score
*/

#ifndef SCORE_HPP_
#define SCORE_HPP_

#include "AObject.hpp"
#include <string>

class Score : public AObject
{
  public:
    Score(const std::string &);
    ~Score();
    void setScore(std::string str);
    void update();

  protected:
  private:
};

#endif /* !SCORE_HPP_ */
