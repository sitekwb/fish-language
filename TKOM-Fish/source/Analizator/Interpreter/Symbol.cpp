//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Symbol.h"

using namespace std;

Symbol::Symbol(Lexer &lexer_){
    lexer = move(lexer_);
}

TokenUP Symbol::getNextToken() {
    if(tokenList.empty()) {
        return move(lexer.getNextToken());
    }
    auto token = move(tokenList.front());
    tokenList.pop_front();
    return move(token);
}

bool Symbol::isConstructed() {
    return constructed;
}

bool Symbol::buildToken(TokenUP &field) {
    auto token = getNextToken();
    bool success = *token == *field;
    field = move(token);
    return success;
}
