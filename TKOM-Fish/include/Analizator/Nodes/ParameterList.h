//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETERLIST_H
#define FISH_PARAMETERLIST_H

#include "Parameter.h"

class ParameterList {
protected:
    std::list<ParameterUP> parameterList;
public:
    ParameterList(std::list<ParameterUP>&&parameterList);
//    void execute(Env &env);
};

using ParameterListUP = std::unique_ptr<ParameterList>;

#endif //FISH_PARAMETERLIST_H
