//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETER_H
#define FISH_PARAMETER_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "Default.h"

class Parameter : public Symbol{
protected:
    TypeUP typeOptional;
    IdentifierUPD identifier;
    TokenUPD equalTokenOptional;
    DefaultUP defaultSymbolOptional;
public:
    Parameter();
    void execute(Env &env) override;
};
using ParameterUP = std::unique_ptr<Parameter>;

#endif //FISH_PARAMETER_H
