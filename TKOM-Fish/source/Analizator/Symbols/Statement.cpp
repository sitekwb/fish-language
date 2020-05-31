//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Symbols/Statement.h"

Statement::Statement() {
    constructed = buildSymbol<CompoundStatement>(compoundStatement)
                  or buildSymbol<SimpleStatement>(simpleStatement);
    if(constructed){
        buildToken(";", semicolonOptional);
    }
}

void Statement::execute() {
    if(!constructed){
        return;
    }

    if(compoundStatement){
        compoundStatement->execute();
    }
    else if(simpleStatement){
        simpleStatement->execute();
    }
}
