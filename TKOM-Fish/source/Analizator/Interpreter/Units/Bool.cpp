//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/Bool.h"

using namespace std;

Bool::Bool() {
    constructed = buildToken("true", boolToken)
            or buildToken("false", boolToken);
    if(constructed) {
        value = boolToken->getValue() == "true";
    }
}

bool Bool::getValue() {
    return value;
}

void Bool::execute() {
    // nothing
}
