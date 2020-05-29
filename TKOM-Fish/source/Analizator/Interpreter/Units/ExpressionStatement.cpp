//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ExpressionStatement.h"

ExpressionStatement::ExpressionStatement() {
    constructed = buildSymbol<Expression>(expression);
}

void ExpressionStatement::execute() {
    if(constructed) {
        expression->execute();
    }
}
