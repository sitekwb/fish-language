//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/AddOperator.h"

AddOperator::AddOperator() {
    constructed = buildToken("+", operatorToken) or buildToken("-", operatorToken);
    if(constructed) {
        value = (operatorToken->getType() == PLUS) ? '+' : '-';
    }
}

void AddOperator::execute() {
//nothing
}

char AddOperator::getChar() {
    return value;
}

