//
// Created by Wojtek on 20/04/2020.
//

#ifndef FISH_SYMBOL_H
#define FISH_SYMBOL_H


#include <vector>
#include "Repeat.h"
#include "SymbolType.h"
#include <list>
#include <initializer_list>
#include <unordered_map>
#include <stack>
#include <memory>


enum Mode {
    Normal,
    Optional,
    Repeat,
    Or,
};

class Symbol {

    std::vector<std::unique_ptr<Symbol>> children;
    SymbolType type;
    std::unique_ptr<Symbol> parent;
    Token token;
    Mode mode;
    size_t currentChildNumber;
    [[maybe_unused]] static inline std::unordered_map<SymbolType, Symbol> rules;
    std::stack<Token> tokenStack;

    void buildChildren();
    Symbol &getCurrentRule();

public:

    // Contructors

    Symbol(Symbol const &);
    Symbol(Symbol&&)=default; //move
    Symbol(Symbol &); //copy
    Symbol& operator=(const Symbol &other);//copy assignment
    Symbol();

    Symbol(std::vector<Symbol> rules);

    Symbol(Mode mode, std::vector<Symbol> symbols);

    explicit Symbol(SymbolType symbolType);

    explicit Symbol(Token token);

    explicit Symbol(TokenType tokenType);

    Symbol(TokenType tokenType, std::string tokenValue);

    explicit Symbol(char c);

    explicit Symbol(std::string tokenValue);



    bool operator==(const Token &token);
    bool operator==(const Mode &mode);

    bool operator!=(const Token &token);
    bool operator!=(const Mode &mode);


    bool isTerminal();

    void addChild(Symbol child);

    size_t getCurrentChildNumber() const;

    const Token &getToken() const;

    SymbolType getType() const;

    Symbol &operator++();

    std::unique_ptr<Symbol> operator++(int);

//    std::unique_ptr<Symbol> getParent();

    static std::unordered_map<SymbolType, Symbol> &getRules();

    bool checkToken(const Token &token);


};


#endif //FISH_SYMBOL_H
