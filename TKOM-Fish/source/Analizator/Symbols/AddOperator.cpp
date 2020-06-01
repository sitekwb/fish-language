//
// Created by Wojtek on 27/05/2020.
//


#include <Analizator/Symbols/AddOperator.h>

AddOperator::AddOperator() {
    constructed = buildToken("+", operatorToken) or buildToken("-", operatorToken);
}

void AddOperator::execute(Env &env) {
//nothing
}


bool AddOperator::getBool() {
    return operatorToken->getType() == PLUS;
}
