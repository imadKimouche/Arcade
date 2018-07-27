/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** mainGui for arcade
*/

#ifndef MAINGUI_HPP_
#define MAINGUI_HPP_

#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
#include <fstream>
#include <sstream>

#include "AException.hpp"
#include "LLoader.hpp"
#include "IGUI.hpp"
#include "IGame.hpp"
#include "Background.hpp"
#include "GameTitle.hpp"
#include "dirent.h"
#include "sys/types.h"
#include "string.h"
#include "LibTitle.hpp"
#include "ArcadeTitle.hpp"
#include "GameThumbnail.hpp"
#include "IObject.hpp"
#include "Score.hpp"
#include "LeftArrow.hpp"
#include "RightArrow.hpp"
#include "PlayerName.hpp"
#include "maxScore.hpp"
#include "currentPlayer.hpp"
#include "ISound.hpp"

class MainGui
{
public:
  MainGui(const std::string libName);//!< ctor
  ~MainGui();//!< dtor
  void run();
  void loadDL();
  void loadThumbnail();
  void loadScore();
  void startGame(std::string, std::string);
  void launchGame();
  void loadScoreMax();
  void writeScore();
  void navigateUp();
  void navigateDown();
  void navigateRight();
  void navigateLeft();
  void blitAndUpdate();
  void switchLibLeft();
  void switchLibRight();
  void initRun();
  void writeName();
  void switchGameLeft();
  void switchGameRight();
  void reloadGame();

private:
  IGUI *(* _make)(void);
  void(* _destroy)(IGUI *gui);
  Data *_gameData;
  IGame *(*_makeGame)(void);
  void (*_destroyGame)(IGame *);
  ISound *(*_smake)(void);
  void(*_sdestroy)(ISound*);
  ISound *_sound;
  IGUI *_gui;
  IGame *_game;
  int _gameNumber;
  int _libNumber;
  std::string getScore(const std::string &);
  std::vector<std::string> _guiLib;
  std::vector<std::string> _gameLib;
  std::map<std::string, std::pair<size_t, size_t>> _thumbnail;
  std::map<std::string, std::string> _scoreFile;
  std::map<std::string, std::string> _scoreMax;

  int _soundMain;
  int _soundPM;
  int _soundArrow;
  int _libIndex;
  int _gameIndex;
  int _lastGameScore;
  int _isWriting;
  int _i;
  int _j;
  int _k;
  IObject::Coordonnes_t _c;
  LLoader *_loader;
  LLoader *_soundLoader;
  LLoader *_gameLoader;
  Data *_data;
  IObject *_bg;
  IObject *_gt;
  IObject *_arcadetitle;
  IObject *_libtitle;
  IObject *_gametitle;
  IObject *_score;
  IObject *_maxScore;
  IObject *_playerName;
  IObject *_leftArrow;
  IObject *_rightArrow;
  IObject *_currentPlayer;
};

#endif /* !MAINGUI_HPP_ */
