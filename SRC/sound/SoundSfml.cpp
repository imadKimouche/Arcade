/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** Sfml sound lib
*/

#include "SoundSfml.hpp"

SoundSfml::SoundSfml()
{
  sf::err().rdbuf(NULL);
}

SoundSfml::~SoundSfml()
{
  for (unsigned int i = 0; i < _tracks.size(); i++)
    _tracks[i]->stop();
  for (unsigned int i = 0; i < _chunks.size(); i++)
    _tracks[i]->stop();
}

int SoundSfml::addTrack(const std::string &path)
{
    std::unique_ptr<sf::Music> music(new sf::Music);

    if (!music->openFromFile(path))
        return -1;
    _tracks.push_back(std::move(music));
    return _tracks.size() - 1;
}

int SoundSfml::addChunk(const std::string &path)
{
    std::unique_ptr<sf::SoundBuffer> buffer(new sf::SoundBuffer);
    std::unique_ptr<sf::Sound> sound(new sf::Sound);

    if (!buffer->loadFromFile(path))
        return -1;
    sound->setBuffer(*(buffer.get()));
    _chunksbuffer.push_back(std::move(buffer));
    _chunks.push_back(std::move(sound));
    return _chunks.size() - 1;
}

void SoundSfml::play(const int &index, const ISound::TYPE &t)
{
    if (t == ISound::TRACK) {
        if (index < 0 || (unsigned int) index >= _tracks.size())
            throw AException("SoundSfml: Play: Track not found");
        //if (_tracks[index].getStatus != sf::SoundSource::Playing)
            _tracks[index]->play();
    } else {
        if (index < 0 || (unsigned int) index >= _chunks.size())
            throw AException("SoundSfml: Play: Chunk not found");
        //if (_chunks[index].getStatus != sf::SoundSource::Status::Playing)
            _chunks[index]->play();
    }
}

void SoundSfml::pause(const int &index, const ISound::TYPE &t)
{
    if (t == ISound::TRACK) {
        if (index < 0 || (unsigned int) index >= _tracks.size())
            throw AException("SoundSfml: Pause: Track not found");
        //if (_tracks[index].getStatus == sf::SoundSource::Status::Playing)
            _tracks[index]->pause();
    } else {
        if (index < 0 || (unsigned int) index >= _chunks.size())
            throw AException("SoundSfml: Pause: Chunk not found");
        //if (_chunks[index].getStatus == sf::SoundSource::Status::Playing)
            _chunks[index]->pause();
    }
}

void SoundSfml::stop(const int &index, const ISound::TYPE &t)
{
    if (t == ISound::TRACK) {
        if (index < 0 || (unsigned int) index >= _tracks.size())
            throw AException("SoundSfml: Stop: Track not found");
        //if (_tracks[index].getStatus == sf::SoundSource::Status::Playing)
            _tracks[index]->stop();
    } else {
        if (index < 0 || (unsigned int) index >= _chunks.size())
            throw AException("SoundSfml: Stop: Chunk not found");
        //if (_chunks[index].getStatus == sf::SoundSource::Playing)
            _chunks[index]->stop();
    }
}

void SoundSfml::setLoop(const int &index, const bool &loop, const ISound::TYPE &t)
{
    if (t == ISound::TRACK) {
        if (index < 0 || (unsigned int) index >= _tracks.size())
            throw AException("SoundSfml: Loop: Track not found");
        _tracks[index]->setLoop(loop);
    } else {
        if (index < 0 ||  (unsigned int) index >= _chunks.size())
            throw AException("SoundSfml: Loop: Chunk not found");
        _chunks[index]->setLoop(loop);
    }
}

extern "C" ISound *make()
{
    return new SoundSfml();
}

extern "C" void destroy(ISound *libsound)
{
    delete libsound;
}
