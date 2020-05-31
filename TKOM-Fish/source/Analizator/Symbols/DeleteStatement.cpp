//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/DeleteStatement.h"

DeleteStatement::DeleteStatement() {
    constructed = buildToken("delete", deleteToken)
            and buildToken(identifier);
}

void DeleteStatement::execute(Env &env) {
    env.destroySymbol(identifier->getValue());
    //done
}
