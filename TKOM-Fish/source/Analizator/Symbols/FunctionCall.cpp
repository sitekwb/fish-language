//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/FunctionCall.h"
#include <Analizator/Symbols/Argument.h>
#include <Analizator/Symbols/Default.h>
#include <Analizator/Symbols/ConditionalExpression.h>
#include <Analizator/Interpreter/ObjectType.h>
#include <Analizator/Interpreter/ReturnException.h>
#include <Analizator/Symbols/FunctionDefinition.h>

FunctionCall::FunctionCall() : object(*this) {
    constructed = buildToken(identifier)
                  and buildToken("(", bracketOpen)
                  and buildSymbol<ArgumentList>(argumentList)
                  and buildToken(")", bracketClose);
}

void FunctionCall::execute(Env &env) {
    auto &function = static_cast<FunctionDefinition &>(env[identifier->getValue()]);
    GlobalEnv argumentEnv;
    auto &parameterList = function.getList();
    auto &argList = argumentList->getList();
    auto aIt = argList.begin();
    for (auto pIt = parameterList.begin(); pIt != parameterList.end(); ++pIt, ++aIt) {
        Obj &parameter = pIt->get();
        if(aIt == argList.end()){
            if(parameter.getBool()) {
                Default &defaultP = static_cast<Default &>(parameter.getObject());
                argumentEnv.setSymbol(parameter.getString(), defaultP);
            }
        }
        Argument &argument = static_cast<Argument &>(aIt->get());
        argumentEnv.setSymbol(parameter.getString(), argument);
    }

    Env funcEnv(argumentEnv);
    try {
        function.execute(funcEnv);
    }
    catch (ReturnException &e) {
        object = *e.getReturnObject();
    }
}


FunctionCall::FunctionCall(std::string name, ArgumentList &otherList) : object(*this) {
    identifier = IdentifierUPD(new Identifier(name), TokenDeleter());
    argumentList = std::make_unique<ArgumentList>(otherList);
}

Obj &FunctionCall::getObject() {
    return object;
}

ObjectType FunctionCall::getObjectType() const {
    return ObjectType::OT_FunctionCall;
}

