//
// Created by Wojtek on 28/05/2020.
//

#include "Analizator/Interpreter/Units/ControlStatement.h"

ControlStatement::ControlStatement() {
    constructed = buildToken("break", controlToken)
            or buildToken("continue", controlToken);
}

void ControlStatement::execute() {
//TODO interpreter with env
}
