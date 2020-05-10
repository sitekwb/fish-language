//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_TOKEN_H
#define FISH_TOKEN_H


#include <ostream>
#include <Analizator/Lexer/TokenType.h>
#include <Context.h>

class Token {
    TokenType type;
    std::string value;
    Context context;
public:
    Token(TokenType tokenType=NO_TOKEN, std::string tokenValue="", Context context=Context());
    Token(char c);
    Token(std::string tokenValue);

    TokenType getType() const;
    const std::string &getValue() const;

    bool operator==(const Token &rhs) const;
    bool operator==(const TokenType &rhs) const;


    bool operator!=(const Token &rhs) const;
    bool operator!=(const TokenType &rhs) const;



    friend std::ostream &operator<<(std::ostream &os, const Token &token);

    static std::unique_ptr<Token> buildKeyword(const std::string& buf);
    static bool isTwoSignTokenSign(char c);
    static bool isSignToken(char c);
    static TokenType getTwoSignTokenType(char c);
    static TokenType getOneSignTokenType(char c);
    static const inline std::unordered_set<std::string> keywords = {"delete", "import", "as", "break", "continue", "alias",
                                                                    "new", "mut", "static", "or", "and", "not",
                                                                    "if", "else", "while", "for", "fori", "foreach", "def", "class",
                                                                    "public", "private", "secret",
                                                                    "true", "false"};
    static const inline std::unordered_set<char> operatorFirstSigns = {'+', '-', '*', '/', '%', '<',
                                                                       '>', '=', '!',};
    static const inline std::unordered_set<char> oneSigns = {'+', '-', '*', '/', '%', '.', ',',
                                                             '{', '}', '(', ')', '[', ']', '=',
                                                             '<', '>', ';', EOF};
};


#endif //FISH_TOKEN_H
