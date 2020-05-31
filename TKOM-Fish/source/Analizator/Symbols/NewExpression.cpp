//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/ClassDefinition.h>
#include "Analizator/Symbols/NewExpression.h"

NewExpression::NewExpression() {
    if(!buildToken("new", newToken)){
        return;
    }
    buildToken("mut", mutTokenOptional);
    buildToken("static", staticTokenOptional);

    buildTypeAndId();

    if(constructed and buildToken("(", bracketOpenOptional)){
        constructed = buildSymbol<ArgumentList>(argumentListOptional)
                and buildToken(")", bracketCloseOptional);
    }
    if(constructed and buildSymbol<AssignOperator>(assignOperatorOptional)){
        constructed = buildSymbol<ConditionalExpression>(conditionalExpression);
    }
}

void NewExpression::execute(Env &env) {
    Token &id = (identifier) ? *identifier : *constant;
    if(conditionalExpression){
        conditionalExpression->execute(env);
        if(staticTokenOptional){
            env.setGlobalSymbol(id.getValue(), *conditionalExpression);
        }
        else{
            env.setSymbol(id.getValue(), *conditionalExpression);
        }
    }
    else{
        // we should call constructor method
        std::string typeName;
        if(typeOptional){
            typeName = typeOptional->getName();
        }
        else{
            typeName = identifier->getValue();
            typeName[0] = toupper(typeName[0]);
            // TODO optionally serve optional errors in typing
        }
        ClassDefinition &cd = dynamic_cast<ClassDefinition &>(env[typeName]);
        if(not argumentListOptional){
            argumentListOptional = std::make_unique<ArgumentList>(0);
        }
        int constructorSize = argumentListOptional.getSize();
        FunctionDefinition &constructor = cd.getConstructor(constructorSize);

        constructorCall = std::make_unique<FunctionCall>(*argumentListOptional);
        Env fcEnv(env);
        fcEnv.setSymbol(CONSTRUCTOR_CONSTANT, *constructorCall);
        constructorCall->execute(fcEnv);
        if(staticTokenOptional){
            env.setGlobalSymbol(id.getValue(), *constructorCall);
        }
        else{
            env.setSymbol(id.getValue(), *constructorCall);
        }
    }
}

void NewExpression::buildTypeAndId() {
    IdentifierUPD id;
    if(buildToken(id)){
        if(buildToken(identifier) or buildToken(CONSTANT, constant)){
            id.reset();
            buildSymbol<Type>(typeOptional);
        }
        else{
            id.reset(); // go back and save in tokenList
            buildToken(identifier);
        }
        constructed = true;
    }
    else {
        constructed = buildToken(CONSTANT, constant);
    }
}
