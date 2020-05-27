//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Interpreter/Units/FunctionDefinition.h"

using namespace std;

FunctionDefinition::FunctionDefinition() {
    constructed = buildToken(def)
            and buildTypeOpt()
            and buildToken(identifier)
            and buildToken(bracketOpen)
            and buildSymbol<ParameterList>(parameterList)
            and buildToken(bracketClose)
            and buildBlockInstruction();
}

void FunctionDefinition::execute() {
//TODO here
}

bool FunctionDefinition::buildTypeOpt() {
    typeOpt = make_unique<Type>();
    // Optional, so always true
    return true;
}

bool FunctionDefinition::buildParameterList() {
    parameterList = make_unique<ParameterList>();
    return parameterList->isConstructed();
}

bool FunctionDefinition::buildBlockInstruction() {
    blockInstruction = make_unique<BlockInstruction>();
    return blockInstruction->isConstructed();
}


