//
// Created by Wojtek on 17/04/2020.
//

#ifndef FISH_SRC_H
#define FISH_SRC_H

#include <memory>
#include <Analizator/Lexer/TokenType.h>

class Src {

public:
    virtual std::string exchangeToken(TokenType tokenType, std::string &value) const = 0;
    virtual char peek() = 0;
    virtual char get() = 0;
    virtual void printDebug(TokenType const &tokenType, std::string const &value) = 0;
    virtual ~Src() = default;
};

typedef std::unique_ptr<Src> SrcT;

#endif //FISH_SRC_H
