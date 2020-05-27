//
// Created by Wojtek on 20/04/2020.
//

#ifndef FISH_SYMBOL_H
#define FISH_SYMBOL_H


#include <vector>
#include "Repeat.h"
#include "SymbolType.h"
#include <list>
#include <initializer_list>
#include <unordered_map>
#include <stack>
#include <memory>
#include <queue>


enum Mode {
    Normal,
    Optional,
    Repeat,
    Or,
};

class Symbol {
    using childIt = std::vector<std::unique_ptr<Symbol>>::iterator;
    using TokenUP = std::unique_ptr<Token>;
    using SymbolUP = std::unique_ptr<Symbol>;

    // MEMBER FIELDS
    Mode mode = Normal;
    SymbolType symbolType = NotNamed;
    std::vector<SymbolUP> children;
    SymbolUP parent;
    Token token;
    childIt currentChildIt;
    [[maybe_unused]] static inline std::unordered_map<SymbolType, Symbol> rules;

    // PRIVATE METHODS
    Symbol &getCurrentRule();
    void copyChildren(const std::vector<std::unique_ptr<Symbol>>&other);
    void rebuildRepeatRule();
    bool isAlmostCompleted() const;
public:
    // USER-DEFINED DEFAULT CONSTRUCTORS
    Symbol(Symbol const &);//copy2
    Symbol(Symbol&&); //move
    Symbol(Symbol &); //copy
    Symbol();
    Symbol& operator=(const Symbol &other);//copy assignment

    // CONSTRUCTORS
    Symbol(Mode mode, std::vector<Symbol> symbols);
    Symbol(std::vector<Symbol> rules);
    explicit Symbol(SymbolType symbolType);
    explicit Symbol(Token token);
    explicit Symbol(TokenType tokenType);
    Symbol(TokenType tokenType, std::string tokenValue);
    explicit Symbol(char c);
    explicit Symbol(std::string tokenValue);
    Symbol(Mode mode, SymbolType symbolType, Token token);


    // GETTERS
    std::unique_ptr<Symbol> getParent();
    Mode getMode() const;
    std::unique_ptr<Symbol> getCurrentChild();
    const childIt &getCurrentChildIt() const;
    Symbol &getCurrentChildRef() const;
    bool isTerminal() const;
    const Token &getToken() const;
    SymbolType getSymbolType() const;
    bool hasChildren() const;
    bool isCompleted() const;
    Mode getChildMode() const;

    static std::unordered_map<SymbolType, Symbol> &getRules();
    const std::vector<std::unique_ptr<Symbol>> &getChildren() const;

    // SETTERS
    void setCurrentChild(std::unique_ptr<Symbol> child);
    void setParent(std::unique_ptr<Symbol>parent);
    void nextChild();

    // EQUALITY OPERATORS
    bool operator==(const Token &token);
    bool operator==(const TokenType &tokenType);
    bool operator==(const Mode &mode);

    bool operator!=(const Token &token);
    bool operator!=(const Mode &mode);
    bool operator!=(const TokenType &tokenType);

    // BUILDERS
    void buildChildren();
    bool nextRuleAfterSuccess();
    bool parseToken(const Token &token);
    std::unique_ptr<std::list<Token>> cleanChild();
    std::unique_ptr<std::list<Token>> getFailedTokenList();

    // CLEANERS
    void previousChild();
    void cleanSymbol();
};


#endif //FISH_SYMBOL_H
