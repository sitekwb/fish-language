//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/FunctionCall.h"

FunctionCall::FunctionCall() {
    constructed = buildToken(identifier)
            and buildToken("(", bracketOpen)
            and buildSymbol<ArgumentList>(argumentList)
            and buildToken(")", bracketClose);
}

void FunctionCall::execute() {
//TODO interprete
}


