//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/AssignOperator.h"

using namespace std;

AssignOperator::AssignOperator() {
    constructed = buildToken("=", assignOperator)
                  or buildToken("+=", assignOperator)
                  or buildToken("-=", assignOperator)
                  or buildToken("*=", assignOperator)
                  or buildToken("/=", assignOperator)
                  or buildToken("%=", assignOperator);
}

const std::string &AssignOperator::getValue() const {
    return value;
}

void AssignOperator::execute() {
    // nothing
}
