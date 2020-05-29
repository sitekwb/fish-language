//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/AssignStatement.h"

AssignStatement::AssignStatement() {
    constructed = buildSymbol<AssignExpression>(assignExpression);
}

void AssignStatement::execute() {
    if(!constructed){
        return;
    }
    assignExpression->execute();
}

