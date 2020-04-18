//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_CONTROLLER_H
#define FISH_CONTROLLER_H

#include <memory>
#include <Analizator/Lexer/Lexer.h>
#include <Context.h>
#include <Src.h>
#include <Analizator/Parser/LanguageParser.h>

class Controller {

    static const inline unsigned int MAX_LINE_LENGTH = 1024;
    std::unique_ptr<Lexer> lexer;
    std::unique_ptr<LanguageParser> parser;
public:
    Controller(std::unique_ptr<Src> source);
    void analise();
};


#endif //FISH_CONTROLLER_H
