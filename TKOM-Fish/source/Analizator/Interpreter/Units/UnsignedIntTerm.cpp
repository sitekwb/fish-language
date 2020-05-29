//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/UnsignedIntTerm.h"

UnsignedIntTerm::UnsignedIntTerm() {
    constructed = buildToken(INT, intToken)
            or buildToken(identifier)
            or buildToken(CONSTANT, constantToken);
}

void UnsignedIntTerm::execute() {
    if(!constructed){
        return;
    }
    //TODO
}
