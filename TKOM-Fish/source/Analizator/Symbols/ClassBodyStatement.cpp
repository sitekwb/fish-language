//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ClassBodyStatement.h"

ClassBodyStatement::ClassBodyStatement()  {
    if(buildSymbol<MemberDefinition>(memberDefinition)){
        objectList.push_back(*memberDefinition);
        constructed = true;
    }
    else if(buildSymbol<FunctionDefinition>(functionDefinition)){
        objectList.push_back(*functionDefinition);
        constructed = true;
    }
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

std::string ClassBodyStatement::getName() const {
    if(functionDefinition){
        return functionDefinition->getName();
    }
    return memberDefinition->getName();
}

ObjectType ClassBodyStatement::getObjectType() const {
    return ObjectType::OT_ClassBodyStatement;
}
