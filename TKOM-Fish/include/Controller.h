//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_CONTROLLER_H
#define FISH_CONTROLLER_H

#include <memory>
#include <Analizator/Lexer.h>
#include <Context.h>
#include <Sources/Source.h>
#include <Analizator/Parser.h>

class Controller {

    std::unique_ptr<Parser> parser;
    SourceUP source;

    void resetFile(FileUP &file);
    void resetFilePart(FilePartUP &filePart);
public:
    Controller(SourceUP source);
    void execute();
};


#endif //FISH_CONTROLLER_H
