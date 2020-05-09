//
// Created by Wojtek on 20/04/2020.
//

#include "Analizator/Parser/Symbol.h"

#include <utility>
#include <memory>
#include <Analizator/Lexer/Token.h>
#include <vector>

using namespace std;

Symbol::Symbol(std::vector<Symbol> symbols) {
    for(auto e: symbols){
        children.push_back(make_unique<Symbol>(e));
    }
}

Symbol::Symbol(SymbolType symbolType) : type(symbolType) {

}

Symbol::Symbol(Token token) : token(token) {

}

Symbol::Symbol(TokenType tokenType) : token(tokenType) {

}

Symbol::Symbol(TokenType tokenType, std::string tokenValue) : token(tokenType, move(tokenValue)) {

}

Symbol::Symbol(char c) : token(c) {

}

Symbol::Symbol(std::string tokenValue) : token(tokenValue) {

}

Symbol::Symbol(Mode mode_, std::vector<Symbol> symbols) : mode(mode_) {
    for(auto e: symbols){
        children.push_back(make_unique<Symbol>(e));
    }
}

//Symbol::Symbol(Mode mode_, Symbol rule) : mode(mode_) {
//    children.push_back(rule);
//}

bool Symbol::operator==(const Token &token2) {
    return isTerminal() && token == token2;
}

bool Symbol::isTerminal() {
    return children.empty() && token != NO_TOKEN;
}


void Symbol::addChild(Symbol child) {
    children.push_back(make_unique<Symbol>(child));
}

SymbolType Symbol::getType() const {
    return type;
}

size_t Symbol::getCurrentChildNumber() const {
    return currentChildNumber;
}


const Token &Symbol::getToken() const {
    return token;
}

Symbol &Symbol::operator++() {

    ++currentChildNumber;
    return *this;
}

std::unique_ptr<Symbol> Symbol::operator++(int) {
    auto tmp = make_unique<Symbol>(*this);
    operator++();
    return move(tmp);
}

Symbol::Symbol() : mode(Normal) {

}



std::unordered_map<SymbolType, Symbol> &Symbol::getRules() {
    return rules;
}

bool Symbol::checkToken(const Token &token) {
    buildChildren();

    auto &rule = getCurrentRule();
    if(rule == Repeat)
    return false;
}

Symbol::Symbol(Symbol &o)  : type(o.type),
                            parent(nullptr), token(o.token), mode(o.mode),
                            currentChildNumber(o.currentChildNumber),
                            tokenStack(o.tokenStack){
    children.clear();
    for(auto &e: o.children){
        children.push_back(make_unique<Symbol>(*e));
    }

}

Symbol &Symbol::operator=(const Symbol &o){
    children.clear();
    for(auto &e: o.children){
        children.push_back(make_unique<Symbol>(*e));
    }
    type = o.type;
    parent = nullptr;
    token = o.token;
    mode = o.mode;
    currentChildNumber = o.currentChildNumber;
    tokenStack = o.tokenStack;
    return *this;
}

Symbol::Symbol(Symbol const &o) {
    operator=(o);
}

bool Symbol::operator==(const Mode &mode_) {
    return this->mode == mode_;
}

bool Symbol::operator!=(const Token &token) {
    return ! (*this == token);
}

bool Symbol::operator!=(const Mode &mode) {
    return ! (*this == mode);
}

void Symbol::buildChildren() {
    //TODO
}

Symbol &Symbol::getCurrentRule() {
    return *children[currentChildNumber];
}


