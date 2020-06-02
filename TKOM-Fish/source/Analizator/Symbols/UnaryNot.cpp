//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/UnaryNot.h"

UnaryNot::UnaryNot() {
    constructed = buildToken("not", notToken)
            or buildToken("!", notToken);
}

void UnaryNot::execute(Env &env) {
    objectList.push_back(*notToken);
    evaluateList();
}

bool UnaryNot::getBool() const {
    return notToken.operator bool();
}

ObjectType UnaryNot::getObjectType() const {
    return ObjectType::OT_UnaryNot;
}
