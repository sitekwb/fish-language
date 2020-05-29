//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/AssignExpression.h"

AssignExpression::AssignExpression() {
    constructed = buildToken(identifier)
            and buildSymbol<AssignOperator>(assignOperator)
            and buildSymbol<Term>(term);
}

void AssignExpression::execute() {
    if(!constructed){
        return;
    }
    //TODO interpreter
}
