//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_LEXER_H
#define FISH_LEXER_H

#include <list>
#include <sstream>
#include <map>
#include "Token.h"
#include <Context.h>
#include <Source.h>

typedef std::unique_ptr<Token> TokenUP;

class Lexer {

    Context context;
    std::unique_ptr<Source> source;

    std::string buf;
    char c;
    TokenUP currentToken;

    bool buildLetterToken();
    bool buildNumberToken();
    bool buildDoubleToken();
    bool buildConstantToken();
    bool buildStringToken();
    bool buildSignToken();

    void collectDigits();
    void collectUpperLetters();
    void collectEscapedString();
    void collectIdentifier();
    void collectString();
    void collect();

    void collectStringSign();
    void nextStringSign();

    void next();
    void save();
public:
    explicit Lexer(std::unique_ptr<Source> source);
    TokenUP getNextToken();

    [[nodiscard]] const SourceUP &getSource() const;
};


#endif //FISH_LEXER_H
