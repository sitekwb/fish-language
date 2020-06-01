//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ClassBodyStatement.h"

ClassBodyStatement::ClassBodyStatement() : object(*this) {
    if(buildSymbol<MemberDefinition>(memberDefinition)){
        object = *memberDefinition;
        constructed = true;
    }
    else if(buildSymbol<FunctionDefinition>(functionDefinition)){
        object = *functionDefinition;
        constructed = true;
    }
}


void ClassBodyStatement::execute(Env &env) {
    if(!constructed){
        return;
    }
    object.get().execute(env);
}

Obj &ClassBodyStatement::getObject() {
    return object;
}

std::string ClassBodyStatement::getName() const {
    return object.get().getName();
}
