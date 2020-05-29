//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/EndOfFileException.h>
#include "Analizator/Interpreter/Symbol.h"
#include "Analizator/Interpreter/TokenDeleter.h"

using namespace std;

LexerUP Symbol::lexer;

std::list<TokenUP> Symbol::tokenList;

Symbol::Symbol(LexerUP lexer_) {
    lexer = move(lexer_);
}

Symbol::TokenUPD Symbol::getNextToken() {
    if(tokenList.empty()) {
        auto token = lexer->getNextToken();
        if(*token == EOF_TOKEN){
            throw EndOfFileException();
        }
        return move(TokenUPD(token.release(), TokenDeleter()));
    }
    auto token = move(tokenList.front());
    tokenList.pop_front();
    return move(TokenUPD(token.release(), TokenDeleter()));
}

bool Symbol::isConstructed() {
    return constructed;
}

bool Symbol::buildToken(TokenUPD &field) {
    auto token = getNextToken();
    bool success = *token == *field;
    if(success) {
        field = move(token);
        return true;
    }
    return false;
}

bool Symbol::buildToken(IdentifierUPD &field) {
    auto token = getNextToken();
    bool success = token->getType() == IDENTIFIER;
    if(success) {
        field = IdentifierUPD(new Identifier(*token), TokenDeleter());
        return true;
    }
    return false;
}


bool Symbol::buildToken(const std::string &s, TokenUPD &field) {
    auto token = TokenUPD(new Token(s), TokenDeleter());
    if(buildToken(token)){
        field = move(token);
        return true;
    }
    TokenDeleter::setTokenSaving(false);
    token.reset();
    TokenDeleter::setTokenSaving(true);
    return false;
}




bool Symbol::buildToken(TokenType tokenType, TokenUPD &field) {
    auto token = TokenUPD(new Token(tokenType), TokenDeleter());
    if(buildToken(token)){
        field = move(token);
        return true;
    }
    TokenDeleter::setTokenSaving(false);
    token.reset();
    TokenDeleter::setTokenSaving(true);
    return false;
}

void Symbol::addToTokenList(TokenUP tokenUP) {
    tokenList.push_back(move(tokenUP));
}

void Symbol::setLexer(LexerUP lexer_) {
    lexer = move(lexer_);
}

LexerUP Symbol::recoverLexerUP() {
    return move(lexer);
}
