//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/Parameter.h"

Parameter::Parameter() {
    buildSymbol<Type>(typeOptional);
    constructed = buildToken(identifier);
    if(constructed and buildToken("=", equalTokenOptional)){
        constructed = buildSymbol<Default>(defaultTokenOptional);
    }
}

void Parameter::execute() {
//TODO
}


