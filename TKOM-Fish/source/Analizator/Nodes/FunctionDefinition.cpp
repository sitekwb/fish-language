//
// Created by Wojtek on 26/05/2020.
//

#include <Analizator/Nodes/FunctionDefinition.h>

using namespace std;

const string &FunctionDefinition::getName() const {
    return name;
}

FunctionDefinition::FunctionDefinition(const std::string &&typeName, const std::string &&name,
                                       ParameterListUP &&parameterList,
                                       BlockInstructionUP &&blockInstruction)
                                       : typeName(move(typeName)),
                                       name(move(name)),
                                       parameterList(move(parameterList)),
                                       blockInstruction(move(blockInstruction)) {

}

