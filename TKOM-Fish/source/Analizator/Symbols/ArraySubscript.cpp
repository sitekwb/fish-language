//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ArraySubscript.h"

ArraySubscript::ArraySubscript() {
    if(!buildToken("[", squareOpen)){
        return;
    }
    // [UnsignedIntTerm]
    buildSymbol<UnsignedIntTerm>(unsignedIntTerm1);
    // [':', [UnsignedIntTerm]]
    buildToken(":", colon) and buildSymbol<UnsignedIntTerm>(unsignedIntTerm2);
    constructed = buildToken("]",squareClose);
    if(!constructed){
        squareClose.reset();
        unsignedIntTerm2.reset();
        colon.reset();
        unsignedIntTerm1.reset();
        squareOpen.reset();
    }
}

void ArraySubscript::execute() {
    //nothing
}

