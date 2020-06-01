//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/EndOfFileException.h>
#include <Analizator/Interpreter/ObjectType.h>
#include <Analizator/Interpreter/NotImplementedException.h>
#include "Analizator/Symbol.h"
#include "Analizator/Tokens/TokenDeleter.h"

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
        reset(field);
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
        reset(token);
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
    reset(token);
    return false;
}




bool Symbol::buildToken(TokenType tokenType, TokenUPD &field) {
    auto token = TokenUPD(new Token(tokenType), TokenDeleter());
    if(buildToken(token)){
        field = move(token);
        return true;
    }
    reset(token);
    return false;
}

void Symbol::addToTokenList(TokenUP tokenUP) {
    tokenList.push_front(move(tokenUP));//TODO here changed
}

void Symbol::setLexer(LexerUP lexer_) {
    lexer = move(lexer_);
}

void Symbol::reset(TokenUPD &token) {
    TokenDeleter::setTokenSaving(false);
    token.reset();
    TokenDeleter::setTokenSaving(true);
}


Object &Symbol::getObject() {
    throw NotImplementedException();
}

ObjectType Symbol::getObjectType() const {
    return ObjectType::OT_Symbol;
}
