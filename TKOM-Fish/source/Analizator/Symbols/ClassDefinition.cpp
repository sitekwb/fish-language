//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Symbols/ClassDefinition.h"

ClassDefinition::ClassDefinition() {
    constructed = buildToken("class", classToken)
            and buildSymbol<Type>(type)
            and buildToken("{", blockOpen)
            and buildSymbol<ClassBody>(classBody)
            and buildToken("}", blockClose);
}

void ClassDefinition::execute() {
//TODO create environment and send to children
}
