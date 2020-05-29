//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ForeachStatement.h"

ForeachStatement::ForeachStatement() {
    constructed = buildToken("foreach",foreachToken)
            and buildToken("(", bracketOpen)
            and buildToken(identifier)
            and buildToken("in", inToken)
            and buildSymbol<ListIdentifier>(listIdentifier)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void ForeachStatement::execute() {
    //TODO interpreter
}