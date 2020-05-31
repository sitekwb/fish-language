//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FUNCTIONCALL_H
#define FISH_FUNCTIONCALL_H


#include "ArgumentList.h"
#include <Analizator/Symbol.h>


class ArgumentList;
using ArgumentListUP = std::unique_ptr<ArgumentList>;

class FunctionCall: public Symbol{
protected:
    IdentifierUPD identifier;
    TokenUPD bracketOpen;
    ArgumentListUP argumentList;
    TokenUPD bracketClose;
public:
    FunctionCall();
    void execute() override;
    friend class Test;
};
using FunctionCallUP = std::unique_ptr<FunctionCall>;

#endif //FISH_FUNCTIONCALL_H
