//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_LEXER_H
#define FISH_LEXER_H

#include <list>
#include <sstream>
#include <map>
#include "Token.h"
#include "LexerState.h"
#include "Context.h"

typedef std::unique_ptr<Token> TokenT;

class Lexer {
    static const inline std::map<LexerState, size_t> maxLength = {
            {S_STR_DBL_QUOTE, 1024},
            {S_STR_SGL_QUOTE, 128},
            {S_INT,           128},
            {S_DBL,           256},
            {S_VARIABLE,      128},
            {S_LOWER_VAR,     128},
            {S_TYPE,          128},
            {S_CONSTANT,      128},
            {S_ZERO, 128}
    };

    LexerState state;
    Context &context;

    void setState(LexerState state);
public:
    explicit Lexer(Context &context);
    TokenT getNextToken(std::istream &is);

};


#endif //FISH_LEXER_H
