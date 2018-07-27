/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** interface for sound gestion
*/

#ifndef ISOUND_HPP_
#define ISOUND_HPP_

#include <string>

class ISound {
public:
    enum TYPE {
        TRACK,
        CHUNK
    };
    virtual ~ISound() {};
    virtual int addTrack(const std::string &path) = 0;
    virtual int addChunk(const std::string &path) = 0;
    virtual void play(const int &index, const TYPE &t) = 0;
    virtual void pause(const int &index, const TYPE &t) = 0;
    virtual void stop(const int &index, const TYPE &t) = 0;
    virtual void setLoop(const int &index, const bool &loop, const TYPE &t) = 0;
};

#endif /* !ISOUND_HPP_ */
