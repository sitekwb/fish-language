//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/MultiplyOperator.h"

MultiplyOperator::MultiplyOperator() {
    constructed = buildToken("*", operatorToken)
            or buildToken("/", operatorToken)
            or buildToken("%", operatorToken);
}

void MultiplyOperator::execute() {
//nothing
}

char MultiplyOperator::getChar() {
    return value;
}
