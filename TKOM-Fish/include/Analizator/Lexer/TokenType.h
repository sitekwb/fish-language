//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_TOKENTYPE_H
#define FISH_TOKENTYPE_H

#include <unordered_set>

enum TokenType{
    STR,
    INT,
    DBL,
    IDENTIFIER,
    CONSTANT,
    KEYWORD,
    // ONE SIGN
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    PERCENT,
    POINT,
    COMMA,
    BLOCK_OPEN,
    BLOCK_CLOSE,
    SQUARE_OPEN,
    SQUARE_CLOSE,
    BRACKET_OPEN,
    BRACKET_CLOSE,
    EQUAL,
    LESS,
    MORE,
    SEMICOLON,
    EOF_TOKEN,
    // OPERATORS:
    PLUS_EQ,
    MINUS_EQ,
    MULTIPLY_EQ,
    DIVIDE_EQ,
    PERCENT_EQ,
    LESS_EQ,
    MORE_EQ,
    EQ_EQ,
    NOT_EQ,
};
#endif //FISH_TOKENTYPE_H
