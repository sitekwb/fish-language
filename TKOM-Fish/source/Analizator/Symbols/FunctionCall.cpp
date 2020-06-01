//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/FunctionCall.h"
#include <Analizator/Symbols/ConditionalExpression.h>
#include <Analizator/Interpreter/ObjectType.h>
#include <Analizator/Symbols/Default.h>
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
        ArgumentUP &argument = *aIt;
        Identifier &parameter = pIt->first;
        DefaultUP &defaultP = pIt->second;
        if (argument) {
            // TODO maybe check types
            argumentEnv.setSymbol(parameter.getValue(), *argument);
        } else if (defaultP) {
            argumentEnv.setSymbol(parameter.getValue(), *defaultP);
        } else {
            throw std::runtime_error("Wrong function arguments");
        }
    }
    Env funcEnv(argumentEnv);
    try {
        function.execute(funcEnv);
    }
    catch (ReturnException &e) {
        object = *e.getReturnObject();
    }
}


FunctionCall::FunctionCall(std::string name, ArgumentList &argumentList) : object(*this) {
    identifier = IdentifierUPD(new Identifier(name), TokenDeleter());
    argumentList = std::make_unique<ArgumentList>(argumentList);
}

Object &FunctionCall::getObject() {
    return object;
}

ObjectType FunctionCall::getObjectType() const {
    return ObjectType::OT_FunctionCall;
}

