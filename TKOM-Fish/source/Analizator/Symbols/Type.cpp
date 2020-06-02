//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Type.h"

Type::Type() {
    constructed = buildToken(identifier);
}


void Type::execute(Env &env) {
    objectList.push_back(*identifier);
    evaluateObject();
}

std::string Type::getName() {
    return identifier->getValue();
}

ObjectType Type::getObjectType() const {
    return ObjectType::OT_Type;
}
