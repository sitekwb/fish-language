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
        constructed = buildSymbol<Default>(defaultOptional);
    }
}

void Parameter::execute(Env &env) {
    if(not constructed){
        return;
    }
    if(typeOptional) {
        typeOptional->execute(env);
    }
    if(defaultOptional) {
        defaultOptional->execute(env);
        objectList.push_back(*defaultOptional);
    }
    evaluateList();
}

bool Parameter::getBool() const {
    return defaultOptional.operator bool();
}

std::string Parameter::getString() const {
    return identifier->getValue();
}

ObjectType Parameter::getObjectType() const {
    return ObjectType::OT_Parameter;
}


