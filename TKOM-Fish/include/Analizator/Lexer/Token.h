//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_TOKEN_H
#define FISH_TOKEN_H


#include <ostream>
#include <Analizator/Lexer/TokenType.h>
#include <Src.h>

class Token {
    TokenType type;
    std::string value;
public:
    Token(TokenType tokenType, std::string tokenValue);
    Token(Src const &source, char c);
    explicit Token(TokenType tokenType);

    bool operator==(const Token &rhs) const;
    bool operator!=(const Token &rhs) const;
    bool operator==(const char &rhs) const;
    bool operator!=(const char &rhs) const;

    TokenType getType() const;

    const std::string &getValue() const;

    friend std::ostream &operator<<(std::ostream &os, const Token &token);

    static const inline std::unordered_set<char> oneSignTokenSet = {'+', '-', '*', '/', '%', '.', ',', '{', '[', '(', ')', ']', '}', '=', '<', '>', ';', EOF, '$'};
    static const inline std::unordered_set<std::string> keywords = {"delete", "import", "as", "break", "continue", "alias",
                                                                    "new", "mut", "static", "or", "and", "not",
                                                                    "if", "else", "while", "for", "fori", "foreach", "def", "class",
                                                                    "public", "private", "secret",
                                                                    "true", "false"};
    static const inline std::unordered_set<std::string> operators = {"+=", "-=", "*=", "/=", "%=", "<=", ">=", "==", "!="};

};


#endif //FISH_TOKEN_H
