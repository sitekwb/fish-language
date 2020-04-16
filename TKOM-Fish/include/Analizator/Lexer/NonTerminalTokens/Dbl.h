//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_DBL_H
#define FISH_DBL_H


#include "ConstantValue.h"
#include <string>
#include <ostream>

class Dbl : public ConstantValue {
    double value;
public:
    Dbl(double dbl);
    Dbl(std::string const &buf);
    void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Dbl &dbl);
};


#endif //FISH_DBL_H
