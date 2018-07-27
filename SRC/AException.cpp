/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** Exception handler
*/

#include "AException.hpp"

AException::AException(const std::string &msg) throw()
{
        _msg = msg;
}

const char* AException::what() const throw()
{
        return _msg.c_str();
}

