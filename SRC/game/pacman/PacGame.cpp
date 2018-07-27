/*
** EPITECH PROJECT, 2018
** Arcade - PacMan
** File description:
** PacGame.cpp
*/

#include "PacGame.hpp"

PacGame::PacGame()
{
}

PacGame::~PacGame()
{
    delete(_board);
    delete(_pacman);
    for (unsigned int i = 0; i < _ghosts.size(); i++)
        delete(_ghosts[i]);
}

void PacGame::init(Data *data)
{
    _data = data;
    _data->setMapX(28);
    _data->setMapY(31);
    _data->setScore(0);
    _data->setSpritesheetname("sprite/pacman.png");
    _board = new PacBoard(data);
    _lives = new Lives("OO");
    _startGame = new StartGame();
    _gameOver = new GameOver();
    _gameWin = new GameWin();
    _pacman = new Pacman(data, _board, this);
    _score = new Score(std::to_string(_data->getScore()));
    _data->addObjects(_board);
    _data->addObjects(_pacman);
    _data->addObjects(_score);
    _data->addObjects(_lives);
    _data->addObjects(_startGame);
    _data->addObjects(new Livestxt());
    _ghosts.push_back(new Ghost(0, _data, _board, _pacman));
    _ghosts.push_back(new Ghost(1, _data, _board, _pacman));
    _ghosts.push_back(new Ghost(2, _data, _board, _pacman));
    _ghosts.push_back(new Ghost(3, _data, _board, _pacman));
    for (unsigned int i = 0; i < _ghosts.size(); i++)
        _data->addObjects(_ghosts[i]);
    _board->setGhostMid(_ghosts);
    _board->setPacMan(_pacman);
    _isOn = true;
    _loop = true;
}

void PacGame::update()
{
  if (_loop){
    if (_isOn){
      sleep(2);
      _startGame->setSize({0, 0});
      _isOn = false;
      _board->setGhost(_ghosts);
    }
    _pacman->update();
    for (unsigned int i = 0; i < _ghosts.size(); i++)
    _ghosts[i]->update();
    if (!_loop) {
      _data->addObjects(_gameOver);
      _pacman->saveScore();
    }
    _board->update();
    _score->setScore(std::to_string(_data->getScore()));
    if (_data->getScore() >= 2440) {
      _data->addObjects(_gameWin);
      _pacman->saveScore();
      _loop = false;
    }
  }
}

void PacGame::stop()
{
  _loop = false;
}

void PacGame::restart()
{
  _isOn = true;
  _startGame->setSize({400,34});
  _board->setPacMan(_pacman);
  _board->setGhostMid(_ghosts);
}

Lives *PacGame::getLives()
{
  return _lives;
}

extern "C" IGame *make()
{
    return new PacGame();
}

extern "C" void destroy(IGame *game)
{
    delete game;
}
