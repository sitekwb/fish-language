//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Type.h"

Type::Type() {
    constructed = buildToken(identifier);
}


void Type::execute(Env &env) {
//nothing
}

std::string Type::getName() {
    return identifier->getValue();
}
