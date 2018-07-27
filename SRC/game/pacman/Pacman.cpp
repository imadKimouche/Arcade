/*
** EPITECH PROJECT, 2018
** Arcade - Pacman
** File description:
** PacmanPlayer.cpp
*/

#include "Pacman.hpp"

Pacman::Pacman(Data *data, PacBoard *board, PacGame *game)
{
  setCoordImg({1 * 32, 4 * 32});
  setSize({32, 32});
  setFont(PFont_t{255, 255, 0, 255, 1, ""});
  setTermpic("C");
  _life = 3;
  _game = game;
  _data = data;
  _board = board;
  _super = false;
  _directionW = 'R';
  _direction = 'R';
}

Pacman::~Pacman()
{
}

bool Pacman::moveValid(const int &x, const int &y)
{
    return (x >= 0 && y >= 0 && x < _data->getMapX() && y < _data->getMapY() - 1 && !_board->getBlock(x, y)->isSolid());
}

void Pacman::eat()
{
  double x = getCoord().x;
  double y = getCoord().y;

  switch (_board->getBlock(x, y)->getType()) {
    case Block::GUM:
      _board->getBlock(x, y)->setType(Block::BACKGROUND);
      _data->setScore(_data->getScore() + 10);
      break;
    case Block::SUPERGUM:
        _board->getBlock(x, y)->setType(Block::BACKGROUND);
        _data->setScore(_data->getScore() + 50);
        _super = true;
    break;
    default:
    break;
  }
}

void Pacman::kill()
{
  _life--;
  _game->getLives()->setLives();
  if (!_life)
    _game->stop();
  else
    _game->restart();
}

bool Pacman::isSuper() const
{
  return _super;
}

void Pacman::look()
{
    if (_data->isKey(M_KEY_UP))
        _directionW = 'U';
    if (_data->isKey(M_KEY_DOWN))
        _directionW = 'D';
    if (_data->isKey(M_KEY_LEFT))
        _directionW = 'L';
    if (_data->isKey(M_KEY_RIGHT))
        _directionW = 'R';
}

void Pacman::move()
{
  double x = getCoord().x;
  double y = getCoord().y;

  switch (_direction) {
    case 'U':
      if (moveValid(x, y - 1))
        go({x, y - 1});
    break;
    case 'D':
      if (moveValid(x, y + 1))
        go({x, y + 1});
    break;
    case 'L':
      if (moveValid(x - 1, y))
        go({x - 1, y});
    break;
    case 'R':
      if (moveValid(x + 1, y))
        go({x + 1, y});
    break;
    default:
      go({x, y});
    break;
  }
}

void Pacman::update()
{
  double x = getCoord().x;
  double y = getCoord().y;

  look();
  if (x != getTogo().x || y != getTogo().y)
      return;
  eat();
  switch (_directionW) {
    case 'U':
      if (moveValid(x, y - 1))
        _direction = _directionW;
    break;
    case 'D':
      if (moveValid(x, y + 1))
        _direction = _directionW;
    break;
    case 'L':
      if (moveValid(x - 1, y))
        _direction = _directionW;
    break;
    case 'R':
      if (moveValid(x + 1, y))
        _direction = _directionW;
    break;
    default:
    break;
  }
  move();
}

void Pacman::saveScore()
{
    std::ifstream file;
    file.open("ressources/score/score.sc");
    std::string score1;
    std::string score2;
    std::string score3;
    std::getline(file, score1);
    std::getline(file, score1);
    std::getline(file, score2);
    std::getline(file, score2);
    std::getline(file, score3);
    std::getline(file, score3);
    file.close();
    std::ofstream file_out;
    file_out.open("ressources/score/score.sc");
    if (stoi(score2) < _data->getScore())
        score2 = std::to_string(_data->getScore());
    file_out << "snake" << "\n";
    file_out << score1 << "\n";
    file_out << "pacman" << "\n";
    file_out << score2 << "\n";
    file_out << "qix" << "\n";
    file_out << score3 << "\n";

}
