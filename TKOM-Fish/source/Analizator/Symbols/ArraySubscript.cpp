//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ArraySubscript.h"

ArraySubscript::ArraySubscript() {
    constructed = buildToken("[", squareOpen)
            and buildSymbol<UnsignedIntTerm>(unsignedIntTerm)
            and buildToken("]", squareClose);
}

void ArraySubscript::execute() {
    //nothing
}

int ArraySubscript::getInt() const{
    return unsignedIntTerm->getValue();
}

Object &ArraySubscript::getObject() {
    return unsignedIntTerm->getObject();
}


