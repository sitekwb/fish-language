//
// Created by Wojtek on 26/05/2020.
//

#include <Analizator/Interpreter/Object.h>

#include "Analizator/Symbols/FilePart.h"

using namespace std;

FilePart::FilePart() {
    constructed = buildSymbol<FunctionDefinition>(functionDefinition)
                  or buildSymbol<ClassDefinition>(classDefinition)
                  or buildSymbol<Statement>(statement);
}

void FilePart::execute(Env &env) {
    if(!constructed) {
        return;
    }
    if(functionDefinition) {
        env.setSymbol(functionDefinition->getName(), *functionDefinition);
    }
    else if(classDefinition) {
        classDefinition->execute(env);
        env.setSymbol(classDefinition->getName(), *classDefinition);
    }
    else if(statement) {
        statement->execute(env);
    }
    //done
}

ObjectType FilePart::getObjectType() const {
    return ObjectType::OT_FilePart;
}

