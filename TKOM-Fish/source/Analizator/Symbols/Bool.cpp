//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Bool.h"

using namespace std;

Bool::Bool() {
    constructed = buildToken("true", boolToken)
            or buildToken("false", boolToken);
    if(constructed) {
        value = boolToken->getValue() == "true";
    }
}

bool Bool::getBool() const{
    return value;
}

void Bool::execute(Env &env) {
    // nothing
    objectList.push_back(*boolToken);
    evaluateObject();
}

ObjectType Bool::getObjectType() const {
    return ObjectType::OT_Bool;
}
