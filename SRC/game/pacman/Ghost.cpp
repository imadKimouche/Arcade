/*
** EPITECH PROJECT, 2018
** Arcade - Pacman
** File description:
** Ghost.cpp
*/

#include "Ghost.hpp"

Ghost::Ghost(const int &n, Data *data, PacBoard *board, Pacman *pacman)
{
    setCoordImg({1 * 32, (double)n * 32});
    setSize({32, 32});
    switch (n) {
      case 0:
          setFont(PFont_t{255, 0, 0, 255, 1, ""});
      break;
      case 1:
          setFont(PFont_t{0, 0, 255, 255, 1, ""});
      break;
      case 2:
          setFont(PFont_t{255, 180, 0, 255, 1, ""});
      break;
      case 3:
          setFont(PFont_t{244, 66, 235, 255, 1, ""});
      break;
      default :
          setFont(PFont_t{255, 255, 255, 255, 1, ""});
      break;
    }
    setTermpic("M");
    _mind = WAIT;
    _data = data;
    _pacman = pacman;
    _board = board;
}

Ghost::~Ghost()
{
}

void Ghost::setDepart(const Coordonnes_t &c)
{
  _depart = c;
  place(c.x, c.y);
}

bool Ghost::moveValid(const int &x, const int &y)
{
    return (x >= 0 && y >= 0 && x < _data->getMapX() && y < _data->getMapY() - 1 && !_board->getBlock(x, y)->isSolid());
}

void Ghost::reset()
{
  place(_depart.x, _depart.y);
}

void Ghost::eat()
{
  double x = getCoord().x;
  double y = getCoord().y;

  if ((x < _pacman->getCoord().x - 0.5 || x > _pacman->getCoord().x + 0.5) || (y < _pacman->getCoord().y - 0.5 || y > _pacman->getCoord().y + 0.5))
    return;
  if (_pacman->isSuper())
    reset();
  else
    _pacman->kill();
}

void Ghost::mindRand()
{
    int d = 0;
    bool valid = false;
    double cx = getCoord().x;
    double cy = getCoord().y;
    int i = 0;

    while (!valid && i < 200) {
      d = rand() % 4;
      switch (d) {
        case 0:
          if (moveValid(cx, cy - 1))
            valid = true;
          _direction = 'U';
          break;
        case 1:
          if (moveValid(cx, cy + 1))
            valid = true;
          _direction = 'D';
          break;
        case 2:
          if (moveValid(cx - 1, cy))
            valid = true;
          _direction = 'L';
          break;
        case 3:
          if (moveValid(cx + 1, cy))
            valid = true;
          _direction = 'R';
          break;
        }
        i++;
    }
}

bool Ghost::move()
{
  Coordonnes_t tmp;
    switch (_direction) {
      case 'U':
        tmp = {getCoord().x, getCoord().y - 1};
      break;
      case 'D':
        tmp = {getCoord().x, getCoord().y + 1};
      break;
      case 'L':
        tmp = {getCoord().x - 1, getCoord().y};
      break;
      case 'R':
        tmp = {getCoord().x + 1, getCoord().y};
      break;
      default:
        return false;
      break;
    }
    if (moveValid(tmp.x, tmp.y))
      go(tmp);
    else
      return false;
    return true;
}

void Ghost::update()
{
    eat();
    if (getCoord().x != getTogo().x || getCoord().y != getTogo().y)
        return;
    if (!move()) {
      mindRand();
    }
}
