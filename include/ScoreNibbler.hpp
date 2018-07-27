/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** score
*/

#ifndef SCORENIBBLER_HPP_
#define SCORENIBBLER_HPP_

#include "AObject.hpp"

class ScoreNibbler : public AObject
{
  public:
    ScoreNibbler(std::string std);
    ~ScoreNibbler();
    void setScore(std::string str);
    void update();

  protected:
  private:
};

#endif /* !SCORE_HPP_ */
