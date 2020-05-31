//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ClassBody.h"

ClassBody::ClassBody() {
    buildRepeatSymbol<ClassBodyStatement>(classBodyStatementList);
    constructed = true;
}

void ClassBody::execute() {
    // TODO interprete
    for(auto &e:classBodyStatementList){
        e->execute();
    }
}
