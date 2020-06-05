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
#include <Sources/Source.h>

class Lexer {

    Context context;
    SourceUP source;

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
    explicit Lexer(SourceUP source);
    TokenUP getNextToken();

    const SourceUP &getSource() const;

};

using LexerUP = std::unique_ptr<Lexer>;


#endif //FISH_LEXER_H
