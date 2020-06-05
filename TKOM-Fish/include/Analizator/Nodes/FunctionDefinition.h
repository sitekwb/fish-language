//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_FUNCTIONDEFINITION_H
#define FISH_FUNCTIONDEFINITION_H


#include "ParameterList.h"
#include "BlockInstruction.h"
#include "ClassStatement.h"

class FunctionDefinition : public ClassStatement{

    const std::string typeName;
    const std::string name;
    ParameterListUP parameterList;
    BlockInstructionUP blockInstruction;
public:

    const std::string &getName() const;

    FunctionDefinition(const std::string &&typeName, const std::string &&name, ParameterListUP &&parameterList,
                       BlockInstructionUP &&blockInstruction);

};
using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;


#endif //FISH_FUNCTIONDEFINITION_H
