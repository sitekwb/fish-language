//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/RelativeOperator.h"

using namespace std;


RelativeOperator::RelativeOperator() {
    constructed = buildToken("==", operatorToken)
            or buildToken("!=", operatorToken)
            or buildToken("<", operatorToken)
            or buildToken(">", operatorToken)
            or buildToken("<=", operatorToken)
            or buildToken(">=", operatorToken);
}

void RelativeOperator::execute(Env &env) {
    objectList.push_back(*operatorToken);
    evaluateList();
}

ObjectType RelativeOperator::getObjectType() const {
    return ObjectType::OT_RelativeOperator;
}

