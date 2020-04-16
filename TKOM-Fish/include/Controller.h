//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_CONTROLLER_H
#define FISH_CONTROLLER_H

#include <memory>
#include <Analizator/Lexer/Lexer.h>
#include "Context.h"
#include <Analizator/Parser/Parser.h>

typedef std::unique_ptr<Lexer> LexerT;
typedef std::unique_ptr<Parser> ParserT;

class Controller {
    static const inline unsigned int MAX_LINE_LENGTH = 1024;
    Context context;
    LexerT lexer;
    ParserT parser;

    void printPrompt(std::ostream &os) const;
    void printTokenDebug(std::ostream &os, Token const &token) const;
public:
    Controller();
    void analise(std::istream &is, std::ostream &os);
};


#endif //FISH_CONTROLLER_H
