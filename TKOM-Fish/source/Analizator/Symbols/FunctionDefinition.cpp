//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Symbols/FunctionDefinition.h"

using namespace std;

FunctionDefinition::FunctionDefinition() {
    // "def"
    if(not buildToken("def", def)){
        return;
    }

    // [Type], identifier
    IdentifierUPD id;
    if(not buildToken(id)){
        return;
    }

    if(buildToken(identifier)){
        id.reset();
        buildSymbol<Type>(typeOptional);
    }
    else{
        id.reset();
        buildToken(identifier);
    }

    // '(', ParameterList, ')', BlockInstruction
    constructed = buildToken("(", bracketOpen)
            and buildSymbol<ParameterList>(parameterList)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

std::string FunctionDefinition::getName() {
    return identifier->getValue();
}

void FunctionDefinition::execute(Env &env) {

}

