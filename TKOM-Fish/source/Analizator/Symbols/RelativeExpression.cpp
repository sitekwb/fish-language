//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/RelativeExpression.h>

RelativeExpression::RelativeExpression() {
    constructed = buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose);
    if(!constructed) {
        constructed = buildSymbol<ArithmeticExpression>(arithmeticExpression);
    }
}

void RelativeExpression::execute(Env &env) {
    if(!constructed){
        return;
    }
    if(conditionalExpression){
        conditionalExpression->execute(env);
        value = conditionalExpression->getValue();
    }
    else if(arithmeticExpression){
        arithmeticExpression->execute(env);
        if(arithmeticExpression->isDouble()){
            value = arithmeticExpression->getDouble() != 0;
        }
        else {
            value = arithmeticExpression->getInt() != 0;
        }
    }
    //done
}

bool RelativeExpression::getValue() {
    return value;
}

