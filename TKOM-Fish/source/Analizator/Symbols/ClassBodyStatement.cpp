//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ClassBodyStatement.h"

ClassBodyStatement::ClassBodyStatement() {
    constructed = buildSymbol<MemberDefinition>(memberDefinition)
                  or buildSymbol<FunctionDefinition>(functionDefinition);
}

std::pair<std::string, Symbol&> ClassBodyStatement::getClassBodyStatementSymbol() {
    if(memberDefinition){
        return {memberDefinition->getName(), *memberDefinition};
    }
    return {functionDefinition->getName(), *functionDefinition};
}

void ClassBodyStatement::execute(Env &env) {
    if(!constructed){
        return;
    }
    if(memberDefinition){
        memberDefinition->execute(env);
    }
    else if(functionDefinition){
        functionDefinition->execute(env);
    }
}
