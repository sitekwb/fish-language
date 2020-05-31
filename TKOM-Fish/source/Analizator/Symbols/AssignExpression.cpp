//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/AssignExpression.h"

AssignExpression::AssignExpression() {
    constructed = buildToken(identifier)
            and buildSymbol<AssignOperator>(assignOperator)
            and buildSymbol<ConditionalExpression>(conditionalExpression);
}

void AssignExpression::execute(Env &env) {
    if(!constructed){
        return;
    }
    assignOperator->execute(env);
    conditionalExpression->execute(env);
    env.setSymbol(identifier->getValue(), conditionalExpression->getReturnObject());
}
