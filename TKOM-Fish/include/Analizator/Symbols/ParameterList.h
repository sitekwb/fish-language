//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETERLIST_H
#define FISH_PARAMETERLIST_H

#include "Parameter.h"
#include <Analizator/Symbol.h>

class Parameter;
using ParameterUP = std::unique_ptr<Parameter>;

class ParameterList : public Symbol{
protected:
    ParameterUP parameter;
    std::list<std::pair<TokenUPD, ParameterUP>> repeatList;

public:
    ParameterList();
    void execute(Env &env) override;
    int getInt()const override;
    ObjectType getObjectType() const override;
};

using ParameterListUP = std::unique_ptr<ParameterList>;

#endif //FISH_PARAMETERLIST_H
