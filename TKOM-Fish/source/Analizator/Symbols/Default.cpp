//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/Default.h"

Default::Default() {
    constructed = buildSymbol<Term>(term);
}

void Default::execute() {
    if(constructed) {
        term->execute();
    }
}
