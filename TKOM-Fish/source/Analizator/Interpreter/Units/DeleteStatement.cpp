//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/DeleteStatement.h"

DeleteStatement::DeleteStatement() {
    constructed = buildToken("delete", deleteToken)
            and buildToken(identifier);
}

void DeleteStatement::execute() {
    //TODO interpreter
}
