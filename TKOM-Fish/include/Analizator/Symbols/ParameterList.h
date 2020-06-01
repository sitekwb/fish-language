//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETERLIST_H
#define FISH_PARAMETERLIST_H

#include "Parameter.h"
#include <Analizator/Symbol.h>

class ParameterList : public Symbol{
protected:
    ParameterUP parameter;
    std::list<std::pair<TokenUPD, ParameterUP>> repeatList;

    std::list<std::reference_wrapper<Obj>>objectList;
public:
    ParameterList();
    void execute(Env &env) override;
    int getInt()const override;
    std::list<std::reference_wrapper<Obj>> &getList();
};

using ParameterListUP = std::unique_ptr<ParameterList>;

#endif //FISH_PARAMETERLIST_H
