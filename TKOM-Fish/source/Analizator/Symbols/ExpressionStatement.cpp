//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ExpressionStatement.h"

ExpressionStatement::ExpressionStatement() {
    constructed = buildSymbol<Expression>(expression);
}

void ExpressionStatement::execute(Env &env) {
    if(constructed) {
        expression->execute(env);
    }
}
