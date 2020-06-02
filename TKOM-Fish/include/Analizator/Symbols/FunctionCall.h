//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FUNCTIONCALL_H
#define FISH_FUNCTIONCALL_H


#include <Analizator/Symbol.h>
#include "ArgumentList.h"
#include "FunctionDefinition.h"


class ArgumentList;
using ArgumentListUP = std::unique_ptr<ArgumentList>;

class FunctionDefinition;
using FunctionDefinitionUP = std::unique_ptr<FunctionDefinition>;

class FunctionCall: public Symbol{
protected:
    IdentifierUPD identifier;
    TokenUPD bracketOpen;
    ArgumentListUP argumentList;
    TokenUPD bracketClose;
    //INTERPRETER
    FunctionDefinitionUP funcCopy;
public:
    FunctionCall();
    // for calling constructors
    FunctionCall(std::string name, ArgumentList &otherList);
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using FunctionCallUP = std::unique_ptr<FunctionCall>;

#endif //FISH_FUNCTIONCALL_H
