//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/AliasStatement.h"

AliasStatement::AliasStatement() {
    constructed = buildToken("alias", aliasKeyword)
            and buildSymbol<Type>(name)
            and buildSymbol<Type>(type);
}

void AliasStatement::execute() {
    if(!constructed){
        return;
    }
//TODO interpreter
}
