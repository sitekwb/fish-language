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
#include "SymbolOld.h"

using R = Symbol;

class Parser {
    std::unique_ptr<Symbol> symbol;
    std::unique_ptr<std::list<Token>> tokenList;
    void expandTreeUntilFoundToken();
    void goDown();
    void goUp();
    bool serveFailure();
    void serveSuccess();
    void parseToken();
    void cleanChild();
public:
    Parser();

    bool parse(Token &nextToken);
    void cleanTree();
    Symbol &getTree();
};


#endif //FISH_PARSER_H
