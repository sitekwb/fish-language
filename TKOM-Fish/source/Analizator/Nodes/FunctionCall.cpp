//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Nodes/FunctionCall.h"

using namespace std;

//
//
//void FunctionCall::execute(Env &env) {
//    Obj &obj = env[identifier->getValue()];
//    argumentList->execute(env);
//    auto &argList = argumentList->evaluateList();
//    if(obj.getObjectType() == ObjectType::OT_Lib){
//        Env localEnv(env);
//        int i = 0;
//        for(auto &e:argList){
//            localEnv.setSymbol("__"+std::to_string(i)+"__", e);
//        }
//        static_cast<Lib &>(obj).execute(localEnv);
//        return;
//    }
//    auto &function = static_cast<FunctionDefinition &>(obj);
//    Env argumentEnv;
//    auto &parameterList = function.evaluateList();
//    auto aIt = argList.begin();
//    for (auto pIt = parameterList.begin(); pIt != parameterList.end(); ++pIt, ++aIt) {
//        Obj &parameter = pIt->get();
//        if(aIt == argList.end()){
//            if(parameter.getBool()) {
//                Default &defaultP = static_cast<Default &>(parameter.getObject());
//                argumentEnv.setSymbol(parameter.getString(), defaultP);
//            }
//        }
//        Argument &argument = static_cast<Argument &>(aIt->get());//TODO maybe later type checking here
//        argumentEnv.setSymbol(parameter.getString(), argument.getObject());
//    }
//
//    Env funcEnv(argumentEnv);
//    funcCopy = std::make_unique<FunctionDefinition>(function);
//    try {
//        funcCopy->execute(funcEnv);
//    }
//    catch (ReturnException &e) {
//        auto &condExprUP = e.getReturnObject();
//        if(condExprUP) {
//            objectList.clear();
//            objectList.push_back(*condExprUP);
//            evaluateObject();
//        }
//    }
//}

FunctionCall::FunctionCall(std::string &&funcName,
                           ArgumentListUP &&argumentList)
        : funcName(move(funcName)),
          argumentList(move(argumentList)) {

}

