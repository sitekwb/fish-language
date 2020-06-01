//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/MultiplyOperator.h"

MultiplyOperator::MultiplyOperator() {
    constructed = buildToken("*", operatorToken)
            or buildToken("/", operatorToken)
            or buildToken("%", operatorToken);
}

void MultiplyOperator::execute(Env &env) {
//nothing
}

int MultiplyOperator::getInt() const {
    return operatorToken->getType();
}


