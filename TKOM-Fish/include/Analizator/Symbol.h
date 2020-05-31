//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_SYMBOL_H
#define FISH_SYMBOL_H


#include <Analizator/Tokens/Token.h>
#include <list>
#include <Analizator/Interpreter/Env.h>
#include <Analizator/Lexer.h>
#include <Analizator/Tokens/Identifier.h>
#include "Analizator/Tokens/TokenDeleter.h"

class Symbol : public Object{
public:
    using SymbolUP = std::unique_ptr<Symbol>;
protected:

    using TokenUPD = std::unique_ptr<Token, TokenDeleter>;
    static std::list<TokenUP> tokenList;
    static LexerUP lexer;

    static TokenUPD getNextToken();

    static bool buildToken(TokenUPD &field);

    static bool buildToken(TokenType tokenType, TokenUPD &field);

    static bool buildToken(const std::string &s, TokenUPD &field);

    static bool buildToken(IdentifierUPD &field);

    template<typename SymbolType>
    static bool buildSymbol(std::unique_ptr<SymbolType> &symbolUP) {
        symbolUP = std::make_unique<SymbolType>();
        if (symbolUP->isConstructed()) {
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
        while (buildSymbol<SymbolType>(symbolUP)) {
            list.push_back(move(symbolUP));
        }
        return true;
    }


    bool constructed = false;
public:
    Symbol(LexerUP lexer);

    Symbol() = default;

    virtual void execute(Env &env) = 0;
    virtual SymbolType getType();

    bool isConstructed();
    static LexerUP recoverLexer();
    static void setLexer(LexerUP lexer);
    static void addToTokenList(TokenUP tokenUP);
    static void reset(TokenUPD &token);

    friend class Test;
};

#endif //FISH_SYMBOL_H
