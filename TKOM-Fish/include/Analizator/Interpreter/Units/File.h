//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FILE_H
#define FISH_FILE_H


#include <list>
#include <Analizator/Lexer/Lexer.h>
#include <Analizator/Interpreter/Symbol.h>
#include "FilePart.h"

class File : public Symbol {
    using FileUP = std::unique_ptr<File>;

    std::list<FilePart> filePartList;
    bool buildFilePart();
public:
    File(Lexer &lexer);
    void execute() override;
};


#endif //FISH_FILE_H
