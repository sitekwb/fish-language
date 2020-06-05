//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_PARAMETER_H
#define FISH_PARAMETER_H

#include "Term.h"


class Parameter{
protected:
    std::string type, name;
    TermUP defaultTermOpt;
public:
    Parameter(std::string &&type, std::string &&name, TermUP &&defaultTerm);
    static const std::string getNodeName();
//    void execute(Env &env);
};
using ParameterUP = std::unique_ptr<Parameter>;

#endif //FISH_PARAMETER_H
