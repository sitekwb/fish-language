//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/Expression.h"

Expression::Expression() {
    constructed = buildSymbol<ArithmeticExpression>(arithmeticExpression)
                  or buildSymbol<NewExpression>(newExpression);
}

void Expression::execute() {
    if(!constructed){
        return;
    }
    if(arithmeticExpression){
        arithmeticExpression->execute();
    }
    if(newExpression){
        newExpression->execute();
    }
    // TODO interprete with final values etc.
}
