//
// Created by Wojtek on 26/05/2020.
//

#include <Analizator/Interpreter/SymbolNotFoundException.h>
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
        // no execute classBodyStatement
        symbols.setSymbol(e->getName(), e->getObject());
    }
}

void ClassDefinition::executeConstructor(Env &env, ArgumentListUP &argumentList){
    if(not argumentList){
        argumentList = std::make_unique<ArgumentList>(0);
    }
    int constructorSize = argumentList->getInt();
    int i=0;
    bool found = true;
    while(found) {
        try {
            std::string name = "__" + std::to_string(i) + getName();
            auto &constructor = static_cast<FunctionDefinition &>(symbols[name]);
            if(constructor.getInt() == constructorSize){
                FunctionCall constructorCall = std::make_unique<FunctionCall>(name, *argumentList);
                constructorCall.execute(env);
                break;
            }
        }
        catch(SymbolNotFoundException &e){
            found = false;
        }
    }

    FunctionDefinition &constructor = classDefinition.getConstructor(constructorSize);

    constructorCall = std::make_unique<FunctionCall>(*argumentListOptional);
    Env fcEnv(env);
    fcEnv.setSymbol(CONSTRUCTOR_CONSTANT, *constructorCall);
    constructorCall->execute(fcEnv);
}

ClassDefinition::ClassDefinition(ClassDefinition &cd) {
    symbols = cd.symbols;
}

ObjectType ClassDefinition::getObjectType() const {
    return ObjectType::OT_ClassDefinition;
}
