//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_SYMBOL_H
#define FISH_SYMBOL_H


#include <Analizator/Lexer/Token.h>
#include <list>
#include <Analizator/Lexer/Lexer.h>



class Symbol {
    using SymbolUP = std::unique_ptr<Symbol>;
protected:
    static std::list<TokenUP>tokenList;
    static Lexer &lexer;
    static TokenUP getNextToken();
    bool constructed = false;
    static bool buildToken(TokenUP &field);

    template<typename SymbolType>
    bool buildSymbol(std::unique_ptr<SymbolType> &symbolUP) {
        symbolUP = make_unique<SymbolType>();
        return symbolUP->isConstructed();
    }

public:
    Symbol(Lexer &lexer);
    Symbol() = default;
    virtual void execute() = 0;
    bool isConstructed();
};


#endif //FISH_SYMBOL_H
