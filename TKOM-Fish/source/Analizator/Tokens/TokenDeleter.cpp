//
// Created by Wojtek on 28/05/2020.
//

#include <Analizator/Tokens/TokenDeleter.h>
#include <Analizator/Symbol.h>

using namespace std;

bool TokenDeleter::shouldTokenBeSaved;

void TokenDeleter::operator()(Token *token) {
    if(shouldTokenBeSaved) {
        Symbol::addToTokenList(make_unique<Token>(*token));
    }
    delete token;
}

TokenDeleter::TokenDeleter() {
    shouldTokenBeSaved = true;
}

void TokenDeleter::setTokenSaving(bool value) {
    shouldTokenBeSaved = value;
}
