//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Symbols/ClassDefinition.h"

ClassDefinition::ClassDefinition() {
    constructed = buildToken("class", classToken)
            and buildSymbol<Type>(type)
            and buildToken("{", blockOpen)
            and buildRepeatSymbol<ClassBodyStatement>(classBodyStatementList)
            and buildToken("}", blockClose);
}

std::string ClassDefinition::getName() {
    return type->getName();
}

void ClassDefinition::execute(Env &env) {
    for(auto &e:classBodyStatementList){
        auto pair = e->getClassBodyStatementSymbol();
        symbols.setSymbol(pair.first, pair.second);
    }
}
