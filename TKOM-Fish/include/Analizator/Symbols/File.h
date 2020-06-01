//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FILE_H
#define FISH_FILE_H


#include <list>
#include <Analizator/Symbol.h>
#include <Analizator/Lexer.h>
#include "FilePart.h"

class File : public Symbol {
    std::list<FilePartUP> filePartList;
    //d
public:
    File();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using FileUP = std::unique_ptr<File>;


#endif //FISH_FILE_H
