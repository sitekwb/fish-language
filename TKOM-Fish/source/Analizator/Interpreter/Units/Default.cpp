//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/Default.h"

Default::Default() {
    constructed = buildSymbol<Term>(term);
}

void Default::execute() {
    if(constructed) {
        term->execute();
    }
}
