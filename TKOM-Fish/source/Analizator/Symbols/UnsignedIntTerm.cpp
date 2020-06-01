//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/UnsignedIntTerm.h>
#include <Analizator/Symbols/Term.h>


UnsignedIntTerm::UnsignedIntTerm() {
    constructed = buildSymbol<Term>(term);
}

void UnsignedIntTerm::execute(Env &env) {
    if(!constructed){
        return;
    }
    term->execute(env);
}

int UnsignedIntTerm::getInt() const{
    return term->getInt();
}

