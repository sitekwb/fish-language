//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ClassBodyStatement.h"

ClassBodyStatement::ClassBodyStatement() {
    constructed = buildSymbol<MemberDefinition>(memberDefinition)
                  or buildSymbol<FunctionDefinition>(functionDefinition);
}

void ClassBodyStatement::execute() {
    // TODO interprete with class environment
    if(!constructed){
        return;
    }
    if(memberDefinition){
        memberDefinition->execute();
    }
    else if(functionDefinition){
        functionDefinition->execute();
    }
}
