//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARRAYSUBSCRIPT_H
#define FISH_ARRAYSUBSCRIPT_H


#include <Analizator/Symbol.h>
#include "UnsignedIntTerm.h"

class UnsignedIntTerm;
using UnsignedIntTermUP = std::unique_ptr<UnsignedIntTerm>;

class ArraySubscript : public Symbol{
protected:
    TokenUPD squareOpen;
    UnsignedIntTermUP unsignedIntTerm;
    TokenUPD squareClose;
public:
    ArraySubscript();
    void execute(Env &env) override;
    int getInt() const override;
    ObjectType getObjectType() const override;
};
using ArraySubscriptUP = std::unique_ptr<ArraySubscript>;


#endif //FISH_ARRAYSUBSCRIPT_H
