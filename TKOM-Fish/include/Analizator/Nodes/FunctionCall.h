//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FUNCTIONCALL_H
#define FISH_FUNCTIONCALL_H

#include <string>
#include "ArgumentList.h"
#include <memory>

class ArgumentList;
using ArgumentListUP = std::unique_ptr<ArgumentList>;

class FunctionCall : public Statement {
protected:
    std::string funcName;
    ArgumentListUP argumentList;
public:
    FunctionCall(std::string &&funcName, ArgumentListUP &&argumentList);

//    void execute(Env &env) override;
};
using FunctionCallUP = std::unique_ptr<FunctionCall>;

#endif //FISH_FUNCTIONCALL_H
