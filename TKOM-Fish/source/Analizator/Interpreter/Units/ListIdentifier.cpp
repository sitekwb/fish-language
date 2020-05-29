//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ListIdentifier.h"

ListIdentifier::ListIdentifier() {
    constructed = buildToken(identifier)
            and buildOptionalSymbol<ArraySubscript>(arraySubscriptOptional);
}

void ListIdentifier::execute() {
    //TODO
}
