//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FUNCTIONCALL_H
#define FISH_FUNCTIONCALL_H


#include <Analizator/Symbol.h>
#include "ArgumentList.h"


class ArgumentList;
using ArgumentListUP = std::unique_ptr<ArgumentList>;


class FunctionCall: public Symbol{
protected:
    IdentifierUPD identifier;
    TokenUPD bracketOpen;
    ArgumentListUP argumentList;
    TokenUPD bracketClose;
    //INTERPRETER
    Object &object;
public:
    FunctionCall();
    // for calling constructors
    FunctionCall(std::string name, ArgumentList &argumentList);
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    Object &getObject();
    friend class Test;
};
using FunctionCallUP = std::unique_ptr<FunctionCall>;

#endif //FISH_FUNCTIONCALL_H
