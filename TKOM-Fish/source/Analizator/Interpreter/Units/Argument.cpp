//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/Argument.h"

Argument::Argument() {
    constructed = buildSymbol<ConditionalExpression>(conditionalExpression);
}

void Argument::execute() {
    if(!constructed){
        return;
    }
    conditionalExpression->execute();
}
