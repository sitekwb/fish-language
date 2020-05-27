//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Interpreter/Units/FilePart.h"

using namespace std;

FilePart::FilePart() {
    constructed = buildFunctionDefinition() or buildClassDefinition() or buildStatement();
}

bool FilePart::buildFunctionDefinition() {
    functionDefinition = make_unique<FunctionDefinition>();
    if(functionDefinition->isConstructed()){
        return true;
    }
    functionDefinition.reset();
    return false;
}


bool FilePart::buildClassDefinition() {
    classDefinition = make_unique<ClassDefinition>();
    if(classDefinition->isConstructed()){
        return true;
    }
    classDefinition.reset();
    return false;
}

bool FilePart::buildStatement() {
    statement = make_unique<Statement>();
    if(statement->isConstructed()){
        return true;
    }
    statement.reset();
    return false;
}

void FilePart::execute() {
    if(isConstructed()){
        functionDefinition->execute();
        classDefinition->execute();
        statement->execute();
    }
}

