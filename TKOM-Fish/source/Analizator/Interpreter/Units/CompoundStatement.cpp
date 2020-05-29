//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/CompoundStatement.h"

CompoundStatement::CompoundStatement() {
    constructed = buildSymbol<IfStatement>(ifStatement)
                  or buildSymbol<WhileStatement>(whileStatement)
                  or buildSymbol<ForStatement>(forStatement)
                  or buildSymbol<ForiStatement>(foriStatement)
                  or buildSymbol<ForeachStatement>(foreachStatement);
}

void CompoundStatement::execute() {
    if(!constructed){
        return;
    }
    if(ifStatement){
        ifStatement->execute();
    }
    else if(whileStatement){
        whileStatement->execute();
    }
    else if(forStatement){
        forStatement->execute();
    }
    else if(foriStatement){
        foriStatement->execute();
    }
    else if(foreachStatement){
        foreachStatement->execute();
    }
    // nothing more
}
