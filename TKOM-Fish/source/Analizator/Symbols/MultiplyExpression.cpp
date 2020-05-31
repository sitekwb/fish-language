//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/MultiplyExpression.h"

MultiplyExpression::MultiplyExpression() {
    buildSymbol<UnarySign>(unarySignOptional);
    constructed = buildSymbol<Term>(term);
}

void MultiplyExpression::execute() {
    if(!constructed){
        return;
    }
    term->execute();
    // TODO interprete
}

bool MultiplyExpression::isDoubleValue() {
    return isDouble;
}

double MultiplyExpression::getDouble() {
    return doubleValue;
}

int MultiplyExpression::getInt() {
    return intValue;
}




