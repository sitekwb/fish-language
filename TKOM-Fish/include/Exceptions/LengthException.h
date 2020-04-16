//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_LENGTHEXCEPTION_H
#define FISH_LENGTHEXCEPTION_H


#include <exception>
#include <stdexcept>
#include "../Analizator/Lexer/LexerState.h"

class LengthException : public std::runtime_error {
    LexerState state;
public:
    LengthException(LexerState lexerState);
};


#endif //FISH_LENGTHEXCEPTION_H
