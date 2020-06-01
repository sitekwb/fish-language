//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FILEPART_H
#define FISH_FILEPART_H

#include <Analizator/Symbol.h>
#include "FunctionDefinition.h"
#include "ClassDefinition.h"
#include "Statement.h"

class FilePart : public Symbol {
    FunctionDefinitionUP functionDefinition;
    ClassDefinitionUP classDefinition;
    StatementUP statement;
public:
    FilePart();
    void execute(Env &environment) override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using FilePartUP = std::unique_ptr<FilePart>;


#endif //FISH_FILEPART_H
