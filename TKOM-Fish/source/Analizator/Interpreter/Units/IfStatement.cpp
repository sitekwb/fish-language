//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/IfStatement.h"

IfStatement::IfStatement() {
    constructed = buildToken("if", ifToken)
            and buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
    if(constructed and buildToken("else", elseOptional)) {
        constructed = constructed and buildSymbol<BlockInstruction>(blockInstruction);
    }
}

void IfStatement::execute() {
//TODO interprete
}
