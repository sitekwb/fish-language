//
// Created by Wojtek on 28/05/2020.
//

#include "Analizator/Symbols/ControlStatement.h"

ControlStatement::ControlStatement() {
    constructed = buildToken("break", controlToken)
            or buildToken("continue", controlToken);
    if(not constructed and buildToken("return", controlToken)){
        buildSymbol<ConditionalExpression>(conditionalExpressionOptional);
        constructed = true;
    }
}

void ControlStatement::execute() {
//TODO interpreter with env
}
