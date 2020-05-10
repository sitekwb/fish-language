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
    for (auto e: symbols) {
        children.push_back(make_unique<Symbol>(e));
    }
    currentChildIt = children.begin();
}

Symbol::Symbol(SymbolType symbolType_) : Symbol() {
    symbolType = symbolType_;
}


//    Mode mode = Normal;
//    SymbolType symbolType = NotNamed;
//    std::vector<SymbolUP> children;
//    SymbolUP parent;
//    Token token;
//    childIt currentChildIt;

Symbol::Symbol(Token token_) : Symbol() {
    token = token_;
}

Symbol::Symbol(TokenType tokenType) : Symbol(Token(tokenType)) {

}

Symbol::Symbol(TokenType tokenType, std::string tokenValue) : Symbol(Token(tokenType, move(tokenValue))) {

}

Symbol::Symbol(char c) : Symbol(Token(c)) {

}

Symbol::Symbol(std::string tokenValue) : Symbol(Token(move(tokenValue))) {

}

Symbol::Symbol(Mode mode_, std::vector<Symbol> symbols) : Symbol(symbols) {
    mode = mode_;
}

//Symbol::Symbol(Mode mode_, Symbol rule) : mode(mode_) {
//    children.push_back(rule);
//}

bool Symbol::operator==(const Token &token2) {
    return isTerminal() && token == token2;
}

bool Symbol::isTerminal() const {
    return children.empty() && token != NO_TOKEN;
}


const Token &Symbol::getToken() const {
    return token;
}


Symbol::Symbol() {
}


std::unordered_map<SymbolType, Symbol> &Symbol::getRules() {
    return rules;
}

Symbol::Symbol(Symbol &o) : symbolType(o.getSymbolType()),
                            parent(nullptr), token(o.token), mode(o.mode) {
    copyChildren(o.children);
    currentChildIt = children.begin();
}

Symbol &Symbol::operator=(const Symbol &o) {
    if (!o.isTerminal() && o.getChildren().empty()) {
        // Copy symbol as a child
        vector<unique_ptr<Symbol>> v;
        v.push_back(make_unique<Symbol>(o));
        copyChildren(v);
    } else {
        copyChildren(o.getChildren());
    }
    token = o.getToken();
    mode = o.getMode();
    currentChildIt = o.getCurrentChildIt();
    symbolType = o.getSymbolType();
    // we don't copy parent
    return *this;
}

Symbol::Symbol(Symbol const &o) : symbolType(o.getSymbolType()),
                                  parent(nullptr), token(o.token), mode(o.mode) {
    copyChildren(o.children);
    currentChildIt = children.begin();
}

bool Symbol::operator==(const Mode &mode_) {
    return this->mode == mode_;
}

bool Symbol::operator!=(const Token &token) {
    return !(*this == token);
}

bool Symbol::operator!=(const Mode &mode) {
    return !(*this == mode);
}

void Symbol::buildChildren() {
    if (children.empty()) {
        auto &rule = rules[symbolType];
        copyChildren(rule.getChildren());
        mode = rule.getMode();
        token = rule.getToken();
    }
}

Symbol &Symbol::getCurrentRule() {
    if (isTerminal()) {
        return *this;
    }
    return **currentChildIt;
}


bool Symbol::parseToken(const Token &token_) {
    if (getCurrentRule() == token_) {
        token = token_;
        return true;
    }
    return false;
}

const vector<std::unique_ptr<Symbol>> &Symbol::getChildren() const {
    return children;
}

void Symbol::copyChildren(const std::vector<std::unique_ptr<Symbol>> &other) {
    children.clear();
    for (auto &e: other) {
        children.push_back(make_unique<Symbol>(*e));
    }
    currentChildIt = children.begin();
}

bool Symbol::nextRuleAfterSuccess() {
    if (*this == Repeat) {
        rebuildRepeatRule();
        return false;
    }
    if (isTerminal()) {
        return true;
    }
    ++currentChildIt;
    if (isCompleted()) {
        // this symbol is completed - go out
        return true;
    }
    // rule not completed
    // there are other symbols left in this rule

    // if symbol is "Or" - go out, because we found one of symbols
    if(*this == Or){
        return true;
    }
    // if symbol is "Normal" or "Optional" - go to next
    return false;
}

bool Symbol::nextRuleAfterFailure() {
    if (isTerminal()) {
        return true;
    }
    if (*this == Normal) {
        // it's not this symbol - go up
        return true;
    }
    // optional was not used - go next
    // or was not used - go next
    // repeat was not used - go next
    // if all symbols are used - go up
    return isCompleted();
}

bool Symbol::isCompleted() {
    return currentChildIt == children.end();
}

unique_ptr<Symbol> Symbol::getParent() {
    return move(parent);
}

Mode Symbol::getMode() const {
    return mode;
}

std::unique_ptr<Symbol> Symbol::getCurrentChild() {
    return move(*currentChildIt);
}

void Symbol::setParent(std::unique_ptr<Symbol> parent_) {
    parent = move(parent_);
}

void Symbol::setCurrentChild(unique_ptr<Symbol> symbol) {
    *currentChildIt = move(symbol);
}

bool Symbol::operator==(const TokenType &tokenType) {
    return token.getType() == tokenType;
}

bool Symbol::operator!=(const TokenType &tokenType) {
    return !(*this == tokenType);
}

Symbol::Symbol(Symbol &&other) {
    *this = other;
    parent = move(other.getParent());
}

void Symbol::rebuildRepeatRule() {
    auto const &ch = **currentChildIt;
    SymbolUP repeatedChild = make_unique<Symbol>(ch.mode, ch.symbolType, ch.token);
    currentChildIt = children.insert(currentChildIt + 1, move(repeatedChild));
}

SymbolType Symbol::getSymbolType() const {
    return symbolType;
}

const Symbol::childIt &Symbol::getCurrentChildIt() const {
    return currentChildIt;
}

Symbol::Symbol(Mode mode_, SymbolType symbolType, Token token_) : Symbol(symbolType){
    mode = mode_;
    token = move(token_);
}

list<Token> &Symbol::getFailedTokenList() {
        list<Token> mainList;

        for (auto &child: children){
            mainList.merge(child->getFailedTokenList());
        }
        return mainList;
}



