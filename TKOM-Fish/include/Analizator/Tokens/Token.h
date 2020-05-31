//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_TOKEN_H
#define FISH_TOKEN_H


#include <ostream>
#include <Analizator/Tokens/TokenType.h>
#include <Context.h>
#include <Analizator/Interpreter/Object.h>

class Token : public Object{
    TokenType type;
    std::string value;
    Context context;
public:
    Token(TokenType tokenType=NO_TOKEN, std::string tokenValue="", Context context=Context());
    Token(TokenType tokenType, Context context);
    Token(char c, Context context=Context());
    Token(std::string tokenValue, Context context=Context());

    const std::string getTypeString() const;
    TokenType getType() const;
    const std::string &getValue() const;
    const std::string getErrorMessage() const;
    Context getContext()const;

    bool operator==(const Token &rhs) const;
    bool operator==(const TokenType &rhs) const;


    bool operator!=(const Token &rhs) const;
    bool operator!=(const TokenType &rhs) const;



    friend std::ostream &operator<<(std::ostream &os, const Token &token);

    static std::unique_ptr<Token> buildKeyword(const std::string& buf, Context &context);
    static bool isTwoSignTokenSign(char c);
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
    friend class Test;
};


#endif //FISH_TOKEN_H
