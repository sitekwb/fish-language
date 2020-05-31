//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/SymbolType.h>
#include "Analizator/Symbols/MultiplyExpression.h"

MultiplyExpression::MultiplyExpression() {
    buildSymbol<UnarySign>(unarySignOptional);
    constructed = buildSymbol<Term>(term);
}

void MultiplyExpression::execute(Env &env) {
    if(!constructed){
        return;
    }
    unarySignOptional->execute(env);
    term->execute(env);
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

SymbolType MultiplyExpression::getType() {
    return SymbolType::MultiplyExpressionType;
}




