//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/AliasStatement.h"

AliasStatement::AliasStatement() {
    constructed = buildToken("alias", aliasKeyword)
            and buildSymbol<Type>(name)
            and buildSymbol<Type>(type);
}

void AliasStatement::execute(Env &env) {
    if(!constructed){
        return;
    }
    env.setSymbol(name->getName(), *type);
}

ObjectType AliasStatement::getObjectType() const {
    return ObjectType::OT_AliasStatement;
}

bool AliasStatement::isFinal() const {
    return true;
}
