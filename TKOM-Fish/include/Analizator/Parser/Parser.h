//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_PARSER_H
#define FISH_PARSER_H

#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include "Symbol.h"

using R = Symbol;

class Parser {
    std::unique_ptr<Symbol> symbol;
    std::queue<Token> tokenQueue;
    void expandTreeUntilFoundToken();
    void goDown();
    void goUp();
    void serveFailure();
    void serveSuccess();
    void saveToken(Token &token);
public:
    Parser();

    void parse(Token &nextToken);
};


#endif //FISH_PARSER_H
