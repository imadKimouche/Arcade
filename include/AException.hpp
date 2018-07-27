/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** AException class header
*/

#ifndef AEXCEPTION_HPP_
        #define AEXCEPTION_HPP_

#include <exception>
#include <string>

class AException : public std::exception {
public:
	AException(const std::string &msg) throw();
	virtual ~AException() throw() {}
	virtual const char* what() const throw();
private:
	std::string _msg; /*!<  Sets the message for the error being thrown*/
};

#endif /* !AEXCEPTION_HPP_ */



