//
// Created by Wojtek on 19/04/2020.
//

#include "Analizator/Parser/Symbol.h"

using namespace std;

Symbol::Symbol(SymbolType symbolType) : type(move(symbolType)), token(NO_TOKEN) {

}

Symbol::Symbol(Token token_) : type(TOKEN), token(move(token_)){

}

void Symbol::addChild(Symbol child) {
    children.push_back(move(child));
}
