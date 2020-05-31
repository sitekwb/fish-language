//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/AssignStatement.h"

AssignStatement::AssignStatement() {
    constructed = buildSymbol<AssignExpression>(assignExpression);
}

void AssignStatement::execute() {
    if(!constructed){
        return;
    }
    assignExpression->execute();
}

