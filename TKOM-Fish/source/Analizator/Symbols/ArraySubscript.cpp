//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ArraySubscript.h"

ArraySubscript::ArraySubscript() {
    constructed = buildToken("[", squareOpen)
            and buildSymbol<UnsignedIntTerm>(unsignedIntTerm)
            and buildToken("]", squareClose);
}

void ArraySubscript::execute(Env &env) {
    //nothing
    objectList.push_back(*unsignedIntTerm);
    evaluateList();
}

int ArraySubscript::getInt() const{
    return objectList.front().get().getInt();
}

ObjectType ArraySubscript::getObjectType() const {
    return ObjectType::OT_ArraySubscript;
}


