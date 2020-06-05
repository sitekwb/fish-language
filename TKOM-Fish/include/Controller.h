//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_CONTROLLER_H
#define FISH_CONTROLLER_H

#include <memory>
#include <Analizator/Lexer/Lexer.h>
#include <Context.h>
#include <Sources/Source.h>
#include <Analizator/Parser/Parser.h>

class Controller {
    LexerUP lexer;
public:
    Controller(SourceUP source);
    void execute();
};


#endif //FISH_CONTROLLER_H
