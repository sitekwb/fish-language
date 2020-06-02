//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/SimpleStatement.h"

SimpleStatement::SimpleStatement() {
    constructed = buildSymbol<DeleteStatement>(deleteStatement)
                  or buildSymbol<ImportStatement>(importStatement)
                  or buildSymbol<NewStatement>(newStatement)
                  or buildSymbol<AssignStatement>(assignStatement)
                  or buildSymbol<ControlStatement>(controlStatement)
                  or buildSymbol<AliasStatement>(aliasStatement)
                  or buildSymbol<ExpressionStatement>(expressionStatement);
}

void SimpleStatement::execute(Env &env) {
    if (expressionStatement) {
        expressionStatement->execute(env);
    } else if (deleteStatement) {
        deleteStatement->execute(env);
    } else if (importStatement) {
        importStatement->initialize(env);
    } else if (newStatement) {
        newStatement->execute(env);
    } else if (assignStatement) {
        assignStatement->execute(env);
    } else if (controlStatement) {
        controlStatement->execute(env);
    } else if (aliasStatement) {
        aliasStatement->execute(env);
    }
}

ObjectType SimpleStatement::getObjectType() const {
    return ObjectType::OT_SimpleStatement;
}
