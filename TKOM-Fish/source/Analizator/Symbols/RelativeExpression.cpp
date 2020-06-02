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
    objectList.clear();
    if(!constructed){
        return;
    }
    if(conditionalExpression){
        conditionalExpression->execute(env);
        objectList.push_back(*conditionalExpression);
    }
    else if(arithmeticExpression){
        arithmeticExpression->execute(env);
        objectList.push_back(*arithmeticExpression);
    }
    evaluateList();
}

ObjectType RelativeExpression::getObjectType() const {
    return ObjectType::OT_RelativeExpression;
}

