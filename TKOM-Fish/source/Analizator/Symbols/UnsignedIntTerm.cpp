//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/UnsignedIntTerm.h>
#include <Analizator/Symbols/Term.h>


UnsignedIntTerm::UnsignedIntTerm() {
    constructed = buildSymbol<Term>(term);
}

void UnsignedIntTerm::execute() {
    if(!constructed){
        return;
    }
    //TODO
}

