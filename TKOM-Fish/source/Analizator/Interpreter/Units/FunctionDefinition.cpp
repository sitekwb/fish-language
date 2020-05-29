//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Interpreter/Units/FunctionDefinition.h"

using namespace std;

FunctionDefinition::FunctionDefinition() {
    constructed = buildToken("def", def)
            and buildOptionalSymbol<Type>(typeOptional)
            and buildToken(identifier)
            and buildToken("(", bracketOpen)
            and buildSymbol<ParameterList>(parameterList)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void FunctionDefinition::execute() {
//TODO interprete
}

