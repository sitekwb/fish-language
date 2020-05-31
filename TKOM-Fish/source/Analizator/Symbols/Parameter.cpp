//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Parameter.h"

Parameter::Parameter() {
    IdentifierUPD id;
    if(not buildToken(id)){
        return;
    }
    if(buildToken(identifier)){
        id.reset();
        buildSymbol<Type>(typeOptional);
    }
    else{
        identifier = move(id);
    }
    constructed = true;
    if(buildToken("=", equalTokenOptional)){
        constructed = buildSymbol<Default>(defaultTokenOptional);
    }
}

void Parameter::execute() {
//TODO
}


