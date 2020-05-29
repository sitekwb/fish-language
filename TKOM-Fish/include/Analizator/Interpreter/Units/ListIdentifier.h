//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_LISTIDENTIFIER_H
#define FISH_LISTIDENTIFIER_H


#include <Analizator/Interpreter/Symbol.h>
#include "ArraySubscript.h"

class ListIdentifier: public Symbol{
protected:
    IdentifierUPD identifier;
    ArraySubscriptUP arraySubscriptOptional;
public:
    ListIdentifier();
    void execute() override;
};
using ListIdentifierUP = std::unique_ptr<ListIdentifier>;

#endif //FISH_LISTIDENTIFIER_H
