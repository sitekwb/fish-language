//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARRAYSUBSCRIPT_H
#define FISH_ARRAYSUBSCRIPT_H


#include <Analizator/Interpreter/Symbol.h>
#include "UnsignedIntTerm.h"

class ArraySubscript : public Symbol{
protected:
    TokenUPD squareOpen;
    UnsignedIntTermUP unsignedIntTerm1;
    TokenUPD colon ;
    UnsignedIntTermUP unsignedIntTerm2;
    TokenUPD squareClose;
public:
    ArraySubscript();
    void execute() override;
};
using ArraySubscriptUP = std::unique_ptr<ArraySubscript>;


#endif //FISH_ARRAYSUBSCRIPT_H
