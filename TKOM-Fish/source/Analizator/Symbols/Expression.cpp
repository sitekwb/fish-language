//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/AssignExpression.h>
#include "Analizator/Symbols/Expression.h"

Expression::Expression() {
    constructed = buildSymbol<NewExpression>(newExpression)
                  or buildSymbol<AssignExpression>(assignExpression)
                  or buildSymbol<ConditionalExpression>(conditionalExpression);
}

void Expression::execute(Env &env) {
    if (!constructed) {
        return;
    }
    if (conditionalExpression) {
        conditionalExpression->execute(env);
    }
    if (newExpression) {
        newExpression->execute(env);
    }
}

Obj &Expression::getObject() {
    if(conditionalExpression){
        return conditionalExpression->getObject();
    }
    return newExpression->getObject();
    //done
}

ObjectType Expression::getObjectType() const {
    return ObjectType::OT_Expression;
}
