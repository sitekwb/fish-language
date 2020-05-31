//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/SymbolType.h>
#include <Analizator/Symbols/Default.h>
#include <Analizator/Interpreter/ReturnException.h>
#include "Analizator/Symbols/FunctionCall.h"

FunctionCall::FunctionCall() : returnObject(*this) {
    constructed = buildToken(identifier)
                  and buildToken("(", bracketOpen)
                  and buildSymbol<ArgumentList>(argumentList)
                  and buildToken(")", bracketClose);
}

void FunctionCall::execute(Env &env) {
    auto &function = env[identifier->getValue()];
    if (function.getType() != SymbolType::FunctionDefinitionType) {
        return;
    }
    GlobalEnv argumentEnv;
    auto &parameterList = function.getParameterList().getList();
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
        returnObject = *e.getReturnObject();
    }
}


FunctionCall::FunctionCall(ArgumentList &argumentList) : returnObject(*this) {
    identifier = IdentifierUPD(new Identifier(CONSTRUCTOR_CONSTANT), TokenDeleter());
    argumentList = std::make_unique<ArgumentList>(argumentList);
}

