//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/WhileStatement.h"

WhileStatement::WhileStatement() {
    constructed = buildToken("while", whileToken)
            and buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void WhileStatement::execute() {
//TODO
}
