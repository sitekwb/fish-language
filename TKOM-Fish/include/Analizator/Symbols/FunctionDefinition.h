//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FUNCTIONDEFINITION_H
#define FISH_FUNCTIONDEFINITION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ParameterList.h"
#include "BlockInstruction.h"

class FunctionDefinition : public Symbol {
    TokenUPD def;
    TypeUP typeOptional;
    IdentifierUPD identifier;
    TokenUPD bracketOpen;
    ParameterListUP parameterList;
    TokenUPD  bracketClose;
    BlockInstructionUP blockInstruction;
public:
    FunctionDefinition();
    void execute() override;
};
using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;


#endif //FISH_FUNCTIONDEFINITION_H
