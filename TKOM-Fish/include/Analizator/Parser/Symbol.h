//
// Created by Wojtek on 19/04/2020.
//

#ifndef FISH_SYMBOL_H
#define FISH_SYMBOL_H


#include <list>
#include "SymbolType.h"

class Symbol {
    SymbolType type;
    Token token;
    std::list<Symbol> children;
public:
    explicit Symbol(SymbolType symbolType);
    explicit Symbol(Token token);
    explicit Symbol(TokenType tokenType);
    explicit Symbol(std::string keyword);
    void addChild(Symbol child);
};

#endif //FISH_SYMBOL_H
