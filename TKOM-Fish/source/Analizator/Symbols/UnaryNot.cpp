//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/UnaryNot.h"

UnaryNot::UnaryNot() {
    constructed = buildToken("not", notToken)
            or buildToken("!", notToken);
}

void UnaryNot::execute() {
//nothing
}