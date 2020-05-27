//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FILEPART_H
#define FISH_FILEPART_H


#include <Analizator/Parser/Symbol.h>
#include "FunctionDefinition.h"
#include "ClassDefinition.h"
#include "Statement.h"

class FilePart {
    std::unique_ptr<Statement> statement;
    std::unique_ptr<FunctionDefinition> functionDefinition;
    std::unique_ptr<ClassDefinition> classDefinition;
public:
    FilePart(Symbol &symbol);
    void execute();
};


#endif //FISH_FILEPART_H
