//
// Created by Wojtek on 27/05/2020.
//


#include <Analizator/Symbols/AddOperator.h>

AddOperator::AddOperator() {
    constructed = buildToken("+", operatorToken) or buildToken("-", operatorToken);
}

void AddOperator::execute(Env &env) {
    objectList.push_back(*operatorToken);
    evaluateList();
}

ObjectType AddOperator::getObjectType() const {
    return ObjectType::OT_AddOperator;
}