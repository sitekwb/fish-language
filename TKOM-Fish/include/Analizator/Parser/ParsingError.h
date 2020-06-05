//
// Created by Wojtek on 03/06/2020.
//

#ifndef FISH_PARSINGERROR_H
#define FISH_PARSINGERROR_H


#include <stdexcept>
#include <Analizator/Lexer/Token.h>

class ParsingError : public std::runtime_error {
public:
    ParsingError(const Token &token, const std::string &shouldBe, const std::string &symbolName);
};


#endif //FISH_PARSINGERROR_H
