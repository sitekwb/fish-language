//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_SYMBOL_H
#define FISH_SYMBOL_H


#include <Analizator/Lexer/Token.h>
#include <list>
#include <Analizator/Lexer/Lexer.h>
#include <Analizator/Interpreter/Identifier.h>
#include "TokenDeleter.h"

class Symbol {
public:
    using SymbolUP = std::unique_ptr<Symbol>;
protected:

    using TokenUPD = std::unique_ptr<Token, TokenDeleter>;
    static std::list<TokenUP>tokenList;
    static LexerUP lexer;
    static TokenUPD getNextToken();
    static bool buildToken(TokenUPD &field);
    static bool buildToken(TokenType tokenType, TokenUPD &field);
    static bool buildToken(const std::string&s, TokenUPD &field);
    static bool buildToken(IdentifierUPD &field);

    template<typename SymbolType>
    static bool buildSymbol(std::unique_ptr<SymbolType> &symbolUP) {
        symbolUP = std::make_unique<SymbolType>();
        if(symbolUP->isConstructed()){
            return true;
        }
        symbolUP.reset();
        return false;
    }

    template<typename SymbolType>
    static bool buildOptionalSymbol(std::unique_ptr<SymbolType> &symbolUP) {
        buildSymbol<SymbolType>(symbolUP);
        return true;
    }

    template<typename SymbolType>
    static bool buildRepeatSymbol(std::list<std::unique_ptr<SymbolType>> &list) {
        std::unique_ptr<SymbolType> symbolUP;
        while(buildSymbol<SymbolType>(symbolUP)){
            list.push_back(move(symbolUP));
        }
        return true;
    }


    bool constructed = false;
public:
    Symbol(LexerUP lexer);
    Symbol() = default;
    virtual void execute() = 0;
    bool isConstructed();

    static LexerUP recoverLexerUP();
    static void setLexer(LexerUP lexer);
    static void addToTokenList(TokenUP tokenUP);
    //friend struct TokenDeleter;
};

#endif //FISH_SYMBOL_H
