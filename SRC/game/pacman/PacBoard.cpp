/*
** EPITECH PROJECT, 2018
** Arcade - Pacman
** File description:
** PacBoard.cpp
*/

#include "PacBoard.hpp"
#include <iostream>

PacBoard::PacBoard(Data *data)
{
  _blocks[00] = Coordonnes_t{400, 400};
  _blocks[04] = Coordonnes_t{3 * 32, 2 * 32};
  _blocks[30] = Coordonnes_t{400, 400};
  _blocks[20] = Coordonnes_t{0, 0};
  _blocks[11] = Coordonnes_t{0, 32};
  _blocks[18] = Coordonnes_t{3 * 32, 32};
  _blocks[17] = Coordonnes_t{4 * 32, 32};
  _blocks[15] = Coordonnes_t{3 * 32, 0};
  _blocks[16] = Coordonnes_t{4 * 32, 0};
  _blocks[19] = Coordonnes_t{6 * 32, 32};
  _blocks[29] = Coordonnes_t{5 * 32, 32};
  _blocks[23] = Coordonnes_t{7 * 32, 32};
  _blocks[24] = Coordonnes_t{8 * 32, 32};
  _blocks[25] = Coordonnes_t{4 * 32, 2 * 32};
  _blocks[27] = Coordonnes_t{5 * 32, 0};
  _blocks[28] = Coordonnes_t{6 * 32, 0};
  _blocks[21] = Coordonnes_t{7 * 32, 0};
  _blocks[22] = Coordonnes_t{8 * 32, 0};
  _blocks[26] = Coordonnes_t{5 * 32, 2 * 32};
  _data = data;
  init();
}

PacBoard::~PacBoard()
{
}

void PacBoard::init()
{
  int k = 0;
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 30; j++) {
      k = map[j][i];
      switch (k) {
      case 04: _map[j][i] = new Block(Block::GUM, i, j, _blocks[04]);
        break;
      case 30: _map[j][i] = new Block(Block::DOOR, i, j, _blocks[30]);
        break;
      case 00: _map[j][i] = new Block(Block::BACKGROUND, i, j, _blocks[00]);
        break;
      default: _map[j][i] = new Block(Block::WALL, i, j, _blocks[k]);;
        break;
      }
      _data->addObjects(_map[j][i]);
    }
  }
}

void PacBoard::update()
{

}

void PacBoard::setPacMan(IObject *pacman)
{
  pacman->place(1, 28);
}

void PacBoard::setGhost(std::vector<Ghost *> ghosts)
{
  ghosts[0]->setDepart({10, 12});
  ghosts[1]->setDepart({18, 16});
  ghosts[2]->setDepart({10, 16});
  ghosts[3]->setDepart({18, 12});
}

void PacBoard::setGhostMid(std::vector<Ghost *> ghosts)
{
  ghosts[0]->setDepart({14, 14});
  ghosts[1]->setDepart({13, 14});
  ghosts[2]->setDepart({13, 13});
  ghosts[3]->setDepart({14, 13});
}

Block* PacBoard::getBlock(int x, int y)
{
  return _map[y][x];
}

int **PacBoard::getBoard() const
{
  int **m = new int*[30];
  for(int i = 0; i < 28; ++i)
    m[i] = new int[30];
  for (int i = 0; i < 28; i++) {
    for (int j = 0; j < 30; j++) {
      if (_map[i][j] == NULL || !_map[i][j]->isSolid())
        m[i][j] = 0;
      else
        m[i][j] = -2;
      }
    }
    return (int**)m;
}
