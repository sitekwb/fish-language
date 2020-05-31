//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/NewExpression.h"

NewExpression::NewExpression() {
    if(!buildToken("new", newToken)){
        return;
    }
    buildToken("mut", mutTokenOptional);
    buildToken("static", staticTokenOptional);

    buildTypeAndId();

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

void NewExpression::buildTypeAndId() {
    IdentifierUPD id;
    if(buildToken(id)){
        if(buildToken(identifier) or buildToken(CONSTANT, constant)){
            id.reset();
            buildSymbol<Type>(typeOptional);
        }
        else{
            id.reset(); // go back and save in tokenList
            buildToken(identifier);
        }
        constructed = true;
    }
    else {
        constructed = buildToken(CONSTANT, constant);
    }
}
