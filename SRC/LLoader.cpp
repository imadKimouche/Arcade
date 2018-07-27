/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** shared library loader
*/

#include "LLoader.hpp"

LLoader::LLoader()
    : _libName(""), _dl(nullptr)
{
}

LLoader::LLoader(const std::string &libName)
{
    _libName = libName;
    _dl = nullptr;
}

LLoader::~LLoader()
{
}

void LLoader::loadLib()
{
    _dl = dlopen(_libName.data(), RTLD_NOW);
    try {
    if (!_dl)
        throw AException((std::string)("Shared library error: ") + dlerror() + "\n");
      } catch (AException &e)
      {
        std::cerr << e.what() << '\n';
        exit(1);
      }
}

void *LLoader::get_sym(const std::string sym)
{
    char *error = nullptr;
    void *returnSym = nullptr;

    dlerror(); // reset the dl error
    if (_dl)
    {
        returnSym = dlsym(_dl, sym.c_str());
        error = dlerror();
        if (error)
            std::cerr << error << std::endl; //Exception handle
    }
    return (returnSym);
}

void LLoader::closeLib()
{
    if (_dl)
        dlclose(_dl);
}

void LLoader::reload(const std::string &libName)
{
closeLib();
_libName = libName;
loadLib();
}

std::string LLoader::getLib() const
{
    return _libName;
}
