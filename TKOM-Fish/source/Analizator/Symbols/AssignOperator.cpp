//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/AssignOperator.h"

using namespace std;

AssignOperator::AssignOperator() {
    constructed = buildToken("=", assignOperator)
                  or buildToken("+=", assignOperator)
                  or buildToken("-=", assignOperator)
                  or buildToken("*=", assignOperator)
                  or buildToken("/=", assignOperator)
                  or buildToken("%=", assignOperator);
}



void AssignOperator::execute(Env &env) {
    // nothing
    objectList.push_back(*assignOperator);
    evaluateObject();
}

ObjectType AssignOperator::getObjectType() const {
    return ObjectType::OT_AssignOperator;
}


