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

int ArraySubscript::getValue() {
    return unsignedIntTerm->getValue();
}


