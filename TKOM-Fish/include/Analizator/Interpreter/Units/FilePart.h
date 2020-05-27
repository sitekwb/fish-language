//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FILEPART_H
#define FISH_FILEPART_H

#include <Analizator/Interpreter/Symbol.h>
#include "FunctionDefinition.h"
#include "ClassDefinition.h"
#include "Statement.h"

class FilePart : public Symbol {
    using FilePartUP = std::unique_ptr<FilePart>;

    std::unique_ptr<Statement> statement;
    std::unique_ptr<FunctionDefinition> functionDefinition;
    std::unique_ptr<ClassDefinition> classDefinition;

    bool buildFunctionDefinition();
    bool buildClassDefinition();
    bool buildStatement();

public:
    FilePart();
    void execute() override;
};


#endif //FISH_FILEPART_H
