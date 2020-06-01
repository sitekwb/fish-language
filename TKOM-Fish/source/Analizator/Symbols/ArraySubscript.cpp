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
}

int ArraySubscript::getInt() const{
    return unsignedIntTerm->getInt();
}

Obj &ArraySubscript::getObject() {
    return unsignedIntTerm->getObject();
}


