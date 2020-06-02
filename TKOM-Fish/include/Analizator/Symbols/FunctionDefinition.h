//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FUNCTIONDEFINITION_H
#define FISH_FUNCTIONDEFINITION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ParameterList.h"
#include "BlockInstruction.h"

class BlockInstruction;
using BlockInstructionUP = std::unique_ptr<BlockInstruction>;

class ParameterList;
using ParameterListUP = std::unique_ptr<ParameterList>;

class FunctionDefinition : public Symbol {
    TokenUPD def;
    TypeUP typeOptional;
    IdentifierUPD identifier;
    TokenUPD bracketOpen;
    ParameterListUP parameterList;
    TokenUPD  bracketClose;
    BlockInstructionUP blockInstruction;
    // INTERPRETER
    BlockInstructionUP &blockInstructionCopy;
public:
    std::string getName();
    FunctionDefinition();
    FunctionDefinition(FunctionDefinition &f);
    void initialize(Env &env);
    void execute(Env &env) override;
    int getInt()const override;
    ObjectType getObjectType() const override;
};
using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;


#endif //FISH_FUNCTIONDEFINITION_H
