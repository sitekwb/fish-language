//
// Created by Wojtek on 20/04/2020.
//

#ifndef FISH_RULE_H
#define FISH_RULE_H


#include "Repeat.h"


enum Mode{
    Normal,
    Optional,
    Repeat,
    Or,
};

class Rule {
    std::list<Rule> rules;
    std::list<Symbol> symbols;
    Mode mode;
public:
    Rule(std::initializer_list<Rule> rules);
    explicit Rule(Symbol symbol);
    explicit Rule(SymbolType symbolType);
    explicit Rule(Token token);
    explicit Rule(TokenType tokenType);
    Rule(TokenType tokenType, std::string tokenValue);
    explicit Rule(char c);
    explicit Rule(std::string tokenValue);
    Rule(Mode mode, std::initializer_list<Rule> rules);
    Rule(Mode mode, Rule rule);
};


#endif //FISH_RULE_H