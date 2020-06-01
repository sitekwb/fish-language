//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Parameter.h"

Parameter::Parameter():defaultObject(*this) {
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
        constructed = buildSymbol<Default>(defaultOptional);
    }
}

void Parameter::execute(Env &env) {
    typeOptional->execute(env);
    defaultOptional->execute(env);
    if(defaultOptional) {
        defaultObject = *defaultOptional;
    }
}

bool Parameter::getBool() const {
    return defaultOptional.operator bool();
}

Obj &Parameter::getObject() {
    return defaultObject;
}

std::string Parameter::getString() const {
    return identifier->getValue();
}


