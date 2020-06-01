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

class FunctionDefinition : public Symbol {
    TokenUPD def;
    TypeUP typeOptional;
    IdentifierUPD identifier;
    TokenUPD bracketOpen;
    ParameterListUP parameterList;
    TokenUPD  bracketClose;
    BlockInstructionUP blockInstruction;
    // INTERP
    std::list<std::reference_wrapper<Obj>>objectList;
public:
    std::string getName();
    FunctionDefinition();
    void execute(Env &env) override;
    int getInt()const override;
    ObjectType getObjectType() const override;
    std::list<std::reference_wrapper<Obj>>&getList();
};
using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;


#endif //FISH_FUNCTIONDEFINITION_H
