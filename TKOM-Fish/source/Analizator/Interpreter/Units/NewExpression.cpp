//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/NewExpression.h"

NewExpression::NewExpression() {
    if(!buildToken("new", newToken)){
        return;
    }
    buildToken("mut", mutTokenOptional);
    buildToken("static", staticTokenOptional);
    buildSymbol<Type>(typeOptional);
    constructed = buildToken(identifier) or buildToken(CONSTANT, constant);
    if(constructed and buildToken("(", bracketOpenOptional)){
        constructed = buildSymbol<ArgumentList>(argumentListOptional)
                and buildToken(")", bracketCloseOptional);
    }
    if(constructed and buildSymbol<AssignOperator>(assignOperatorOptional)){
        constructed = buildSymbol<ConditionalExpression>(conditionalExpression);
    }
}

void NewExpression::execute() {
//TODO
}
