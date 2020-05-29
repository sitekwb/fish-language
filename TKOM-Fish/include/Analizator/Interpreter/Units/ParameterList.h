//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETERLIST_H
#define FISH_PARAMETERLIST_H


#include <Analizator/Interpreter/Symbol.h>
#include "Parameter.h"

class ParameterList : public Symbol{
protected:
    ParameterUP parameter;
    std::list<std::pair<TokenUPD, ParameterUP>> repeatList;
public:
    ParameterList();
    void execute() override;
};

using ParameterListUP = std::unique_ptr<ParameterList>;

#endif //FISH_PARAMETERLIST_H
