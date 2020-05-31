//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Argument.h"

Argument::Argument() {
    constructed = buildSymbol<ConditionalExpression>(conditionalExpression);
}

void Argument::execute(Env &env) {
    if(!constructed){
        return;
    }
    conditionalExpression->execute(env);
}
