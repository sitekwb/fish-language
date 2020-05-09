//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_PARSER_H
#define FISH_PARSER_H

#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include "Symbol.h"

using R = Symbol;

class Parser {
    std::unique_ptr<Symbol> symbol;
public:
    Parser();

    void parse(Token &nextToken);
};


#endif //FISH_PARSER_H
