//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_TOKENTYPE_H
#define FISH_TOKENTYPE_H

#include <unordered_set>

enum TokenType{
    ONE_SIGN,
    STR,
    INT,
    DBL,
    IDENTIFIER,
    CONSTANT,
    KEYWORD,
    OPERATOR,
    NO_TOKEN,
};
#endif //FISH_TOKENTYPE_H
