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

void Statement::execute(Env &env) {
    if(!constructed){
        return;
    }

    if(compoundStatement){
        compoundStatement->execute(env);
    }
    else if(simpleStatement){
        simpleStatement->execute(env);
    }
}

ObjectType Statement::getObjectType() const {
    return ObjectType::OT_Statement;
}
