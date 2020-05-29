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

using TokenUP = std::unique_ptr<Token>;

class Lexer {

    Context context;
    Source &source;

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
    explicit Lexer(Source &source);
    TokenUP getNextToken();

    Lexer &operator= (const Lexer&lexer);
    [[nodiscard]] const Source &getSource() const;
};

using LexerUP = std::unique_ptr<Lexer>;


#endif //FISH_LEXER_H
