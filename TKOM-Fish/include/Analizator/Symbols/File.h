//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FILE_H
#define FISH_FILE_H


#include <list>
#include <Analizator/Lexer.h>
#include <Analizator/Symbol.h>
#include "FilePart.h"

class File : public Symbol {
    std::list<FilePartUP> filePartList;
public:
    File();
    void execute() override;
    friend class Test;
};
using FileUP = std::unique_ptr<File>;


#endif //FISH_FILE_H
