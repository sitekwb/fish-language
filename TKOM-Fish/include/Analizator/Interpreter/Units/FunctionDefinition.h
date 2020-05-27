//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FUNCTIONDEFINITION_H
#define FISH_FUNCTIONDEFINITION_H


#include <Analizator/Interpreter/Symbol.h>
#include "Type.h"
#include "ParameterList.h"
#include "BlockInstruction.h"

class FunctionDefinition : public Symbol {
    using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;

    TokenUP def = std::make_unique<Token>("def");
    TypeUP typeOpt;
    TokenUP identifier = std::make_unique<Token>(IDENTIFIER);
    TokenUP bracketOpen = std::make_unique<Token>('(');
    ParameterListUP parameterList;
    TokenUP  bracketClose = std::make_unique<Token>(')');
    BlockInstructionUP blockInstruction;

    bool buildTypeOpt();
    bool buildParameterList();
    bool buildBlockInstruction();
public:
    FunctionDefinition();
    void execute() override;
};


#endif //FISH_FUNCTIONDEFINITION_H
