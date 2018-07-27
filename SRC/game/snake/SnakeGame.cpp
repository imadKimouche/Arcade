 /*
** EPITECH PROJECT, 2018
** Arcade - Snake
** File description:
** Game.cpp
*/

#include "Snake.hpp"

SnakeGame::SnakeGame()
{
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::SnakeGame::addObjects(AObject *obj)
{
    this->_data->addObjects(obj);
}

Data *SnakeGame::SnakeGame::getData()
{
    return this->_data;
}

void SnakeGame::SnakeGame::end()
{
    this->state = 2;
}

void SnakeGame::SnakeGame::init(Data *data)
{
    score = 0;
    _gameOver = new GameOver();
    this->_data = data;
    board = new Board(this);
    this->_data->addObjects(board);
    snake = new SnakeHead(this);
    this->points = new ScoreNibbler("0");
    this->points->place(10,0);
    this->_data->addObjects(snake);
    this->_data->setSpritesheetname("sprite/snake.png");
    this->_data->setMapX(board->getX());
    this->_data->setMapY(board->getY() + 1);
    this->state = 0;
    this->speed = 1;
    this->tik_count = 0;
    this->_data->addObjects(points);
    this->board->init();
}

void SnakeGame::SnakeGame::update()
{
    if (this->state == 0 && this->_data->isKey(M_KEY_ENTER)){
        this->state = 1;
    }
    if (this->state == 1 && this->snake->moveFinished()){
        this->tik_count = 0;
        this->snake->move();
    }
    else {
        this->tik_count++;
    }
    if (tik_count >= 50){
        int x = this->snake->getTogo().x;
        int y = this->snake->getTogo().y;
        this->snake->place(x, y);
    }
    if (this->state == 1 && this->_data->isKey(M_KEY_UP))
        this->snake->change_face('U');
    if (this->state == 1 && this->_data->isKey(M_KEY_DOWN))
        this->snake->change_face('D');
    if (this->state == 1 && this->_data->isKey(M_KEY_LEFT))
        this->snake->change_face('L');
    if (this->state == 1 && this->_data->isKey(M_KEY_RIGHT))
        this->snake->change_face('R');
    if (this->state == 2){
        this->changeScore();
        _data->addObjects(_gameOver);

    }
}

void SnakeGame::SnakeGame::changeScore()
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
    if (stoi(score1) < this->score)
        score1 = std::to_string(this->score);
    file_out << "snake" << "\n";
    file_out << score1 << "\n";
    file_out << "pacman" << "\n";
    file_out << score2 << "\n";
    file_out << "qix" << "\n";
    file_out << score3 << "\n";

}

void SnakeGame::SnakeGame::addScore(int value)
{
    std::string sc = "Score :";
    score += value;
    this->_data->setScore(score);
    sc += std::to_string(score);
    this->points->setScore(sc);
    this->points->place(board->getX() - sc.size(), 0);
}

bool SnakeGame::SnakeGame::isLegal(int x, int y)
{
    return this->board->isLegal(x, y);
}

int SnakeGame::SnakeGame::getFood(int x, int y)
{
    return this->board->getFood(x, y);
}

bool SnakeGame::SnakeGame::isSnake(int x, int y)
{
    return this->snake->isHere(x, y);
}
int SnakeGame::getScore() const
{
  return score;
}

extern "C" IGame *make()
{
    return new SnakeGame();
}

extern "C" void destroy(IGame *game)
{
    delete game;
}
