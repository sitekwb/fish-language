//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/UnarySign.h"

UnarySign::UnarySign() {
    constructed = buildToken("+", token) or buildToken("-", token);
}

void UnarySign::execute(Env &env) {
    objectList.push_back(*token);
    evaluateList();
}

bool UnarySign::getBool() const {
    return token->getType() == PLUS;
}

ObjectType UnarySign::getObjectType() const {
    return ObjectType::OT_UnarySign;
}
