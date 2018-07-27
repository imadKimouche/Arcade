/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** Sfml sound lib header file
*/

#ifndef SOUNDSFML_HPP_
#define SOUNDSFML_HPP_

#include "ISound.hpp"
#include "AException.hpp"
#include <SFML/Audio.hpp>
#include <utility>
#include <memory>
#include <vector>

class SoundSfml : public ISound {
public:
    SoundSfml();
    ~SoundSfml();
    int addTrack(const std::string &path);
    int addChunk(const std::string &path);
    void play(const int &index, const ISound::TYPE &t);
    void pause(const int &index, const ISound::TYPE &t);
    void stop(const int &index, const ISound::TYPE &t);
    void setLoop(const int &index, const bool &loop, const ISound::TYPE &t);
private:
    std::vector<std::unique_ptr<sf::Sound>> _chunks;
    std::vector<std::unique_ptr<sf::SoundBuffer>> _chunksbuffer;
    std::vector<std::unique_ptr<sf::Music>> _tracks;
};

#endif /* !SOUNDSFML_HPP_ */
