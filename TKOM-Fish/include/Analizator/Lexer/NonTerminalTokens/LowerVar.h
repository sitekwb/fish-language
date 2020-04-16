//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_LOWERVAR_H
#define FISH_LOWERVAR_H


#include <string>
#include <ostream>
#include "Variable.h"

class LowerVar : public Variable {
public:
    explicit LowerVar(std::string name_);
    void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const LowerVar &var);
};


#endif //FISH_LOWERVAR_H
