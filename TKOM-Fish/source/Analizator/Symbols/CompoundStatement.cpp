//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ReturnException.h>
#include "Analizator/Symbols/CompoundStatement.h"

CompoundStatement::CompoundStatement() {
    constructed = buildSymbol<IfStatement>(ifStatement)
                  or buildSymbol<WhileStatement>(whileStatement)
                  or buildSymbol<ForStatement>(forStatement)
                  or buildSymbol<ForiStatement>(foriStatement)
                  or buildSymbol<ForeachStatement>(foreachStatement);
}

void CompoundStatement::execute(Env &env) {
    if(!constructed){
        return;
    }
    if(ifStatement){
        ifStatement->execute(env);
    }
    try {
        if (whileStatement) {
            whileStatement->execute(env);
        } else if (forStatement) {
            forStatement->execute(env);
        } else if (foriStatement) {
            foriStatement->execute(env);
        } else if (foreachStatement) {
            foreachStatement->execute(env);
        }
    }
    catch(BreakException &e){

    }
    // nothing more
}

ObjectType CompoundStatement::getObjectType() const {
    return ObjectType::OT_CompoundStatement;
}
