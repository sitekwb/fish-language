//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_LEXER_H
#define FISH_LEXER_H

#include <list>
#include <sstream>
#include <map>
#include "Token.h"
#include <Context.h>
#include <Src.h>

typedef std::unique_ptr<Token> TokenT;

class Lexer {
    static const inline std::map<TokenType, size_t> maxLength = {
            {ONE_SIGN, 8},
            {STR, 1024},
            {INT, 128},
            {DBL, 256},
            {IDENTIFIER, 128},
            {CONSTANT, 128},
            {KEYWORD, 128},
            {OPERATOR, 64},
    };

    std::unique_ptr<Context> context;
    std::unique_ptr<Src> source;

    std::string buf;
    char c;
    TokenType potentialType;

    void saveAndnext();
    void next();
    void save();
public:
    Lexer(std::unique_ptr<Context> context, std::unique_ptr<Src> source);
    TokenT getNextToken();

    const std::unique_ptr<Context> &getContext() const;

    const SrcT &getSource() const;

};


#endif //FISH_LEXER_H
