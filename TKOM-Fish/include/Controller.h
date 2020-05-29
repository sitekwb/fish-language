//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_CONTROLLER_H
#define FISH_CONTROLLER_H

#include <memory>
#include <Analizator/Lexer/Lexer.h>
#include <Context.h>
#include <Source.h>
#include <Analizator/Parser/Parser.h>

class Controller {

    static const inline unsigned int MAX_LINE_LENGTH = 1024;
    std::unique_ptr<Parser> parser;
    Source &source;
    bool isDebug;
    bool isFileSource;

public:
    Controller(Source &source, bool isDebug, bool isFileSource);
    void execute();
};


#endif //FISH_CONTROLLER_H
