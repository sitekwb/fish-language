//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ForiStatement.h"

ForiStatement::ForiStatement() {
    constructed = buildToken("fori", foriToken)
            and buildToken("(", bracketOpen)
            and buildSymbol<UnsignedIntTerm>(unsignedIntTerm)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void ForiStatement::execute() {
    //TODO interprete
}
