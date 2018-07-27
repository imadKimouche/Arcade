/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** shared library loader
*/

#ifndef LLOADER_HPP_
#define LLOADER_HPP_

#include <iostream>
#include <dlfcn.h>

#include "AException.hpp"

class LLoader
{
  public:
    LLoader();//!< ctor
    LLoader(const std::string &libName);//!< ctor
    ~LLoader();//!< dtor

    void loadLib();
    void *get_sym(const std::string sym);
    void closeLib();
    void reload(const std::string &);
    std::string getLib() const;

  protected:
  private:
    std::string _libName;
    void *_dl;
};

#endif /* !LLOADER_HPP_ */
