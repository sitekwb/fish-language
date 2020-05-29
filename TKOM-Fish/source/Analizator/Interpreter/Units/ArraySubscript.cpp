//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ArraySubscript.h"

ArraySubscript::ArraySubscript() {
    constructed = buildToken("(", squareOpen);
    // [UnsignedIntTerm]
    buildSymbol<UnsignedIntTerm>(unsignedIntTerm1);
    // [':', [UnsignedIntTerm]]
    buildToken(":", colon) and buildSymbol<UnsignedIntTerm>(unsignedIntTerm2);
    constructed = constructed and buildToken(")",squareClose);
}

void ArraySubscript::execute() {
    //nothing
}

