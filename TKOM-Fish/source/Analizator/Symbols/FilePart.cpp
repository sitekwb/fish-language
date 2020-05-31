//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Symbols/FilePart.h"

using namespace std;

FilePart::FilePart() {
    constructed = buildSymbol<FunctionDefinition>(functionDefinition)
                  or buildSymbol<ClassDefinition>(classDefinition)
                  or buildSymbol<Statement>(statement);
}

void FilePart::execute() {
    if(!constructed) {
        return;
    }
    if(functionDefinition) {
        functionDefinition->execute();
    }
    else if(classDefinition) {
        classDefinition->execute();
    }
    else if(statement) {
        statement->execute();
    }
    //done
}

