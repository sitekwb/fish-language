//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/SimpleStatement.h"

SimpleStatement::SimpleStatement() {
    constructed = buildSymbol<ExpressionStatement>(expressionStatement)
                  or buildSymbol<DeleteStatement>(deleteStatement)
                  or buildSymbol<ImportStatement>(importStatement)
                  or buildSymbol<NewStatement>(newStatement)
                  or buildSymbol<AssignStatement>(assignStatement)
                  or buildSymbol<ControlStatement>(controlStatement)
                  or buildSymbol<AliasStatement>(aliasStatement);
}

void SimpleStatement::execute() {
    if(expressionStatement) {
        expressionStatement->execute();
    }
    else if(deleteStatement) {
        deleteStatement->execute();
    }
    else if(importStatement) {
        importStatement->execute();
    }
    else if(newStatement) {
        newStatement->execute();
    }
    else if(assignStatement){
        assignStatement->execute();
    }
    else if(controlStatement){
        controlStatement->execute();
    }
    else if(aliasStatement){
        aliasStatement->execute();
    }
}
