//
// Created by Wojtek on 04/06/2020.
//

#ifndef FISH_METHODCALL_H
#define FISH_METHODCALL_H

#include <list>
#include <memory>
#include <string>
#include "FunctionCall.h"

class FunctionCall;
using FunctionCallUP = std::unique_ptr<FunctionCall>;

class MethodCall : public Statement{
    std::list<std::string> idNameList;
    FunctionCallUP functionCall;
public:
    MethodCall(std::list<std::string> &&idNameList, FunctionCallUP &&functionCall);
};

using MethodCallUP = std::unique_ptr<MethodCall>;

#endif //FISH_METHODCALL_H
