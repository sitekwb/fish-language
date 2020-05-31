//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ForStatement.h"


ForStatement::ForStatement() {
    constructed = buildToken("for", forToken)
            and buildToken("(", bracketOpen)
            and buildOptionalSymbol<Expression>(expression1Optional)
            and buildToken(";",semicolon1)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(";",semicolon2)
            and buildOptionalSymbol<Expression>(expression2Optional)
            and buildToken(")",bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}


void ForStatement::execute() {
//TODO interpreter
}
