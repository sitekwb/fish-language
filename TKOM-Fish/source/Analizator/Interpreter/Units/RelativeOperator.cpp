//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/RelativeOperator.h"

using namespace std;


RelativeOperator::RelativeOperator() {
    constructed = buildToken("==", operatorToken)
            or buildToken("!=", operatorToken)
            or buildToken("<", operatorToken)
            or buildToken(">", operatorToken)
            or buildToken("<=", operatorToken)
            or buildToken(">=", operatorToken);
}

const std::string &RelativeOperator::getValue() const {
    return value;
}

void RelativeOperator::execute() {
    //nothing
}

