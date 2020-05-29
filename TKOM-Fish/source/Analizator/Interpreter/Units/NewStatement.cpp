//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/NewStatement.h"

NewStatement::NewStatement() {
    constructed = buildSymbol<NewExpression>(newExpression);
}

void NewStatement::execute() {
    if(!constructed){
        return;
    }
    newExpression->execute();
}
