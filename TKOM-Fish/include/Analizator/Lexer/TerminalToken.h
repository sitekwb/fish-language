//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_TERMINALTOKEN_H
#define FISH_TERMINALTOKEN_H

#include <unordered_set>
#include "Token.h"

enum TerminalEnum {
    SEMICOLON = ';',
    NEWLINE = '\n',
    PLUS = '+',
    MINUS = '-',
    MULTIPLY = '*',
    DIVIDE = '/',
    PERCENT = '%',
    POINT = '.',
    COMMA = ',',
    END = EOF,
    EQUAL = '=',
    BRACKET_CIRCLE_OPEN = '(',
    BRACKET_SQUARE_OPEN = '[',
    BLOCK_OPEN = '{',
    BRACKET_CIRCLE_CLOSE = ')',
    BRACKET_SQUARE_CLOSE = ']',
    BLOCK_CLOSE = '}',
    DOLLAR = '$',
    LESS = '<',
    MORE = '>',
};

class TerminalToken : public Token {
    TerminalEnum terminalEnum;
public:
    explicit TerminalToken(TerminalEnum terminal);
    static const inline std::unordered_set<char> tokenSet = {';', '+', '-', '*', '/', '%', '.', ',', '{', '[', '(', ')', ']', '}', '=', '<', '>', '$', EOF};
    void print(std::ostream &os) const;
};

#endif //FISH_TERMINALTOKEN_H
