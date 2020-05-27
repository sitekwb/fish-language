//
// Created by Wojtek on 26/05/2020.
//

#include "Analizator/Interpreter/Units/FilePart.h"

using namespace std;

FilePart::FilePart(Symbol &symbol) {
    if(symbol.getSymbolType() != FilePart){
        throw runtime_error("Wrong symbol type in FilePartClass constructor");
    }

    auto &child = symbol.getCurrentChildRef();
    switch(child.getSymbolType()){
        case Statement:
            statement = make_unique<Statement>(child);
            break;
        case FunctionDefinition:
            functionDefinition = make_unique<FunctionDefinition>(child);
            break;
        case ClassDefinition:
            classDefinition = make_unique<ClassDefinition>(child);
            break;
        default:
            throw runtime_error("Unexpected type");
    }

}
