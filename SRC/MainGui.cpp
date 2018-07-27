/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** mainGui for arcade
*/

#include "MainGui.hpp"
#include <string.h>
#include <stdio.h>

MainGui::MainGui(const std::string libName)
{
  _libNumber = 0;
  _gameNumber = 0;
  loadDL();
  loadThumbnail();
  loadScore();
  loadScoreMax();

  _libIndex = 0;
  _gameIndex = 0;
  _isWriting = 0;
  _i = 0;
  _j = 0;
  _k = 0;
  _loader = new LLoader(libName);
  _soundLoader = new LLoader("./sound/lib_sound_sfml.so");
  _data = new Data();
  _bg = new Background();
  _gt = new GameThumbnail();
  _arcadetitle = new ArcadeTitle("ARCADE");
  _libtitle = new LibTitle(_guiLib[0]);
  _gametitle = new GameTitle(_gameLib[0]);
  _score = new Score("best score : " + _scoreFile[_gameLib[0]]);
  _maxScore = new maxScore("player: " + _scoreMax[_gameLib[0]]);
  _playerName = new PlayerName("");
  _leftArrow = new LeftArrow();
  _rightArrow = new RightArrow();
  _currentPlayer = new currentPlayer("current player ");
  _data->setMapX(38);
  _data->setMapY(22);
  _data->setSpritesheetname("./ressources/image/spritesheet.png");
  _data->addObjects(_bg);
  _data->addObjects(_gt);
  _data->addObjects(_arcadetitle);
  _data->addObjects(_gametitle);
  _data->addObjects(_libtitle);
  _data->addObjects(_score);
  _data->addObjects(_maxScore);
  _data->addObjects(_leftArrow);
  _data->addObjects(_rightArrow);
  _data->addObjects(_playerName);
  _data->addObjects(_currentPlayer);
}

MainGui::~MainGui()
{
}

void MainGui::run()
{
  initRun();
  while (!_data->isStop())
  {
    if (_data->isKey(M_KEY_ENTER))
      launchGame();
    writeName();
    if (_data->isKey(M_KEY_UP))
      navigateUp();
    else if (_data->isKey(M_KEY_DOWN))
      navigateDown();
    if (_data->isKey(M_KEY_RIGHT))
      navigateRight();
    else if (_data->isKey(M_KEY_LEFT))
      navigateLeft();
    if (_data->isKey(M_KEY_P))
      switchLibRight();
    if (_data->isKey(M_KEY_O))
      switchLibLeft();
    blitAndUpdate();
  }
  _destroy(_gui);
  _sdestroy(_sound);
}

void MainGui::loadDL()
{
  DIR *dir = opendir("./lib");
  if (dir)
  {
    struct dirent *dp;
    while ((dp = readdir(dir)) != nullptr)
    {
      if (strcmp(dp->d_name, ".a") && strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
      {
        std::string file(dp->d_name);
        if ((file.substr(file.find("."), file.size())).compare(".so"))
          throw AException("MainGui: file " + file + " is not a shared library");
        std::string newFile = file.substr(file.find_last_of("_") + 1, file.size() - file.find_last_of("_") - 4);
        _guiLib.push_back(newFile);
        _libNumber++;
      }
    }
  }
  else if (ENOENT == errno)
  {
    throw AException("MainGui: directory ./lib does not exist!");
  }
  closedir(dir);
  dir = opendir("./games");
  if (dir)
  {
    struct dirent *dp;
    while ((dp = readdir(dir)) != nullptr)
    {
      if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, ".."))
      {
        std::string file(dp->d_name);
        if ((file.substr(file.find("."), file.size())).compare(".so"))
          throw AException("MainGui: file " + file + " is not a shared library");
        std::string newFile = file.substr(file.find_last_of("_") + 1, file.size() - file.find_last_of("_") - 4);
        _gameLib.push_back(newFile);
        _gameNumber++;
      }
    }
  }
  else if (ENOENT == errno)
  {
    throw AException("MainGui: directory ./game does not exist!");
  }
  closedir(dir);
}

void MainGui::loadThumbnail()
{
  for (size_t i = 0; i < _gameLib.size(); i++)
  {
    _thumbnail[_gameLib[i]].first = 0;
    _thumbnail[_gameLib[i]].second = 0;
  }
  for (auto &it : _thumbnail)
  {
    if (it.first == "nibbler")
      it.second = std::make_pair(1280, 0);
    else if (it.first == "pacman")
      it.second = std::make_pair(1580, 0);
    else if (it.first == "qix")
      it.second = std::make_pair(1580, 202);
    else if (it.first == "centipede")
      it.second = std::make_pair(1580, 404);
    else if (it.first == "solarfox")
      it.second = std::make_pair(1280, 432);

    else
      it.second = std::make_pair(1280, 200);
  }
}

void MainGui::loadScore()
{
  std::string line;
  std::ifstream file("./ressources/score/score.sc");
  if (file.is_open())
  {
    while (getline(file, line))/* message */
    {
      std::string game = line;
      getline(file, line);
      _scoreFile[game] = line;
    }
    file.close();
  }
  else
    throw AException("MainGui: Unable to open score file!");
}

void MainGui::loadScoreMax()
{
  std::string line;
  std::ifstream file("./ressources/score/maxPlayerName");
  if (file.is_open())
  {
    while (getline(file, line))
    {
      std::string game = line;
      getline(file, line);
      _scoreMax[game] = line;
    }
    file.close();
  }
  else
    throw AException("MainGui: Unable to open max score file!");
}

void MainGui::startGame(std::string strGame, std::string strLib)
{
  char flag = 0;
  _gameData = new Data();
  _loader->reload("./lib/lib_arcade_" + strLib + ".so");
  std::string game("./games/lib_arcade_" + strGame + ".so");
  _gameLoader = new LLoader(game);
  _gameLoader->loadLib();
  _makeGame = (IGame * (*)()) _gameLoader->get_sym("make");
  _game = _makeGame();
  _game->init(_gameData);
  _make = (IGUI * (*)()) _loader->get_sym("make");
  _gui = _make();
  _gui->start(_gameData);
  _destroy = (void (*)(IGUI *))_loader->get_sym("destroy");
  _destroyGame = (void (*)(IGame *))_gameLoader->get_sym("destroy");
  _sound->stop(_soundMain, ISound::TRACK);
  _sound->play(_soundPM, ISound::TRACK);
  _sound->setLoop(_soundPM, true, ISound::TRACK);
  while (!_gameData->isStop())
  {
    _gui->keyHandler();
    _gui->update();
    _game->update();
    if (_gameData->isKey(M_KEY_N)){
      flag = 'n';
      if (_gameIndex < _gameNumber - 1){
          _gameIndex++;
          break;
      }
    }
    if (_gameData->isKey(M_KEY_B)){
      flag = 'b';
    if (_gameIndex > 0){
          _gameIndex--;
          break;
      }
    }
    sleep(0.01);
  }
  _destroy(_gui);
  _destroyGame(_game);
  _loader->closeLib();
  _gameLoader->closeLib();
  _lastGameScore = _gameData->getScore();
  if (flag == 'n')
    switchGameRight();
  if (flag == 'b')
    switchGameLeft();
  _sound->stop(_soundPM, ISound::TRACK);
  _sound->play(_soundMain, ISound::TRACK);
}

void MainGui::launchGame()
{
  _destroy(_gui);
  _loader->closeLib();
  startGame(_gameLib[_j], _guiLib[_i]);
  _loader->loadLib();
  _gui = _make();
  _gui->start(_data);
  if (_scoreFile[_gameLib[_j]].size() != 0)
    if (_lastGameScore > std::stoi(_scoreFile[_gameLib[_j]]))
      writeScore();
  loadScore();
  loadScoreMax();
  _data->releaseKey(M_KEY_ENTER);
}

void MainGui::writeScore()
{
    std::fstream file("ressources/score/maxPlayerName");
     if (!file)
          return;

     int currentLine = 0;
     while (currentLine < _j + 1)
     {
          file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          ++currentLine;
     }
     file.seekp(file.tellg());
     file << _playerName->getTermpic() + '\n';
}
void MainGui::navigateUp()
{
  _k--;
  if (_k < 0)
    _k = 0;
  _sound->play(_soundArrow, ISound::CHUNK);
  _leftArrow->place(14, 15);
  _rightArrow->place(23, 15);
  _data->releaseKey(M_KEY_UP);
}

void MainGui::navigateDown()
{
  _k++;
  if (_k > 1)
    _k = 1;
  _sound->play(_soundArrow, ISound::CHUNK);
  _leftArrow->place(14, 17);
  _rightArrow->place(23, 17);
  _data->releaseKey(M_KEY_DOWN);
}

void MainGui::navigateRight()
{
  if (!_k)
    {
      _j++;
      if (_j > _gameNumber - 1)
        _j = _gameNumber - 1;
    }
    else
    {
      _i++;
      if (_i > _libNumber - 1)
        _i = _libNumber - 1;
    }
    _sound->play(_soundArrow, ISound::CHUNK);
    _data->releaseKey(M_KEY_RIGHT);
}

void MainGui::navigateLeft()
{
  if (!_k)
  {
    _j--;
    if (_j < 0)
      _j = 0;
  }
  else
  {
    _i--;
    if (_i < 0)
      _i = 0;
  }
  _sound->play(_soundArrow, ISound::CHUNK);
  _data->releaseKey(M_KEY_LEFT);
}

void MainGui::writeName()
{
  if (_data->isKey(M_KEY_SPACE))
  _isWriting = 1;
  _data->releaseKey(M_KEY_SPACE);
  if (_isWriting)
    _isWriting = _gui->txtHandler(_playerName);
  else
  _gui->keyHandler();

}

void MainGui::switchLibLeft()
{
  if (_libIndex > 0)
    _libIndex--;
  else
    return;
  _destroy(_gui);
  std::string lib("./lib/lib_arcade_" + _guiLib[_libIndex] + ".so");
  _loader->reload(lib);
  _make = (IGUI * (*)()) _loader->get_sym("make");
  _destroy = (void (*)(IGUI *))_loader->get_sym("destroy");
  _gui = _make();
  _gui->start(_data);
  _data->releaseKey(M_KEY_O);
}

void MainGui::switchLibRight()
{
  if (_libIndex < _libNumber - 1)
  _libIndex++;
  else
  return;
  _destroy(_gui);
  std::string lib("./lib/lib_arcade_" + _guiLib[_libIndex] + ".so");
  _loader->reload(lib);
  _make = (IGUI * (*)()) _loader->get_sym("make");
  _destroy = (void (*)(IGUI *))_loader->get_sym("destroy");
  _gui = _make();
  _gui->start(_data);
  _data->releaseKey(M_KEY_P);
}

void MainGui::initRun()
{
  _soundLoader->loadLib();
  _smake = (ISound *(*)())_soundLoader->get_sym("make");
  _sdestroy = (void(*)(ISound*))_soundLoader->get_sym("destroy");
  _sound = _smake();
  _soundMain = _sound->addTrack("./ressources/sounds/Bit_Rush.wav");
  _soundPM = _sound->addTrack("./ressources/sounds/Tetris.ogg");
  _soundArrow = _sound->addChunk("./ressources/sounds/tic.wav");
  _sound->play(_soundMain, ISound::TRACK);
  _loader->loadLib();
  _make = (IGUI * (*)()) _loader->get_sym("make");
  _destroy = (void (*)(IGUI *))_loader->get_sym("destroy");
  _gui = _make();
  _gui->start(_data);
}

void MainGui::blitAndUpdate()
{
  _libtitle->setTermpic(_guiLib[_i]);
  _score->setTermpic("best score : " + _scoreFile[_gameLib[_j]]);
  _maxScore->setTermpic("player: " + _scoreMax[_gameLib[_j]]);
  _c.x = _thumbnail[_gameLib[_j]].first;
  _c.y = _thumbnail[_gameLib[_j]].second;
  _gt->setCoordImg(_c);
  _gametitle->setTermpic(_gameLib[_j]);
  _gui->update();
  sleep(0.01);
}

void MainGui::switchGameLeft()
{
  startGame(_gameLib[_j], _guiLib[_gameIndex]);
  _data->releaseKey(M_KEY_B);
}

void MainGui::switchGameRight()
{
  startGame(_gameLib[_j], _guiLib[_gameIndex]);
  _data->releaseKey(M_KEY_N);
}

void MainGui::reloadGame()
{

}
