//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_UNKNOWNSIGNEXCEPTION_H
#define FISH_UNKNOWNSIGNEXCEPTION_H


#include <stdexcept>

class UnknownSignException : public std::runtime_error {
    char value;
public:
    explicit UnknownSignException(char c);
};


#endif //FISH_UNKNOWNSIGNEXCEPTION_H
