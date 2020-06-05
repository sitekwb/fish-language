//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_TOKEN_H
#define FISH_TOKEN_H


#include <Context.h>
#include <unordered_set>
#include <variant>
#include <string>
#include "TokenType.h"

using TokenVariant = std::variant<std::string,int,double,bool>;

class Token {
    TokenType type;
    TokenVariant value;
    Context context;
public:
    Token(TokenType tokenType, std::string &value, Context context=Context());
    Token(TokenType tokenType, int value, Context context=Context());
    Token(TokenType tokenType, double value, Context context=Context());
    Token(TokenType tokenType, bool value, Context context=Context());

    Token(TokenType tokenType, Context context);
    Token(TokenVariant &tokenVariant, Context context = Context());
    Token(char c, Context context=Context());

    const TokenVariant &getValue() const;
    const std::string getStringValue() const;
    TokenType getType() const;
    const std::string getErrorMessage() const;

    bool operator==(const Token &rhs) const;
    bool operator==(const TokenType &rhs) const;
    bool operator==(const std::string &rhs) const;
//    bool operator==(const bool &rhs) const;
//    bool operator==(const int &rhs) const;
//    bool operator==(const double &rhs) const;


    bool operator!=(const Token &rhs) const;
    bool operator!=(const TokenType &rhs) const;
    bool operator!=(const std::string &rhs) const;
//    bool operator!=(const bool &rhs) const;
//    bool operator!=(const int &rhs) const;
//    bool operator!=(const double &rhs) const;

    static std::unique_ptr<Token> buildKeyword(const TokenVariant &v, Context &context);
    static bool isTwoSignTokenSign(char c);
    const std::string getTypeString() const;
    static bool isSignToken(char c);
    static TokenType getTwoSignTokenType(char c);
    static TokenType getOneSignTokenType(char c);
    static const inline std::unordered_set<std::string> keywords = {"delete", "import", "as", "break", "continue", "alias",
                                                                    "new", "mut", "static", "or", "and", "not",
                                                                    "if", "else", "while", "for", "fori", "foreach", "def", "class",
                                                                    "public", "private", "secret",
                                                                    "true", "false", "return"};
    static const inline std::unordered_set<char> operatorFirstSigns = {'+', '-', '*', '/', '%', '<',
                                                                       '>', '=', '!',};
    static const inline std::unordered_set<char> oneSigns = {'+', '-', '*', '/', '%', '.', ',',
                                                             '{', '}', '(', ')', '[', ']', '=',
                                                             '<', '>', ';', '!', EOF};
};

using TokenUP = std::unique_ptr<Token>;

#endif //FISH_TOKEN_H
