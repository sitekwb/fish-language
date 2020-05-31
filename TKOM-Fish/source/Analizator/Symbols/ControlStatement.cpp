//
// Created by Wojtek on 28/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include <Analizator/Interpreter/ReturnException.h>
#include "Analizator/Symbols/ControlStatement.h"

ControlStatement::ControlStatement() {
    constructed = buildToken("break", controlToken)
                  or buildToken("continue", controlToken);
    if (not constructed and buildToken("return", controlToken)) {
        buildSymbol<ConditionalExpression>(conditionalExpressionOptional);
        constructed = true;
    }
}

void ControlStatement::execute(Env &env) {
    if (!constructed) {
        return;
    }
    if (controlToken->getValue() == "break") {
        throw BreakException();
    }
    if (controlToken->getValue() == "continue") {
        throw ContinueException();
    }
    throw ReturnException(conditionalExpressionOptional);
}
