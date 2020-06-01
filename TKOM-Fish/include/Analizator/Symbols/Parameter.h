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
    DefaultUP defaultOptional;
    //INTERP
    std::reference_wrapper<Obj>defaultObject;
public:
    Parameter();
    void execute(Env &env) override;
    bool getBool()const override;//returns if has default parameter
    Obj &getObject()override;
    std::string getString()const override;
};
using ParameterUP = std::unique_ptr<Parameter>;

#endif //FISH_PARAMETER_H
