//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_INT_H
#define FISH_INT_H


#include <string>
#include <ostream>
#include "ConstantValue.h"

class Int : public ConstantValue {
    int value;
public:
    explicit Int(int val);
    explicit Int(std::string const &buf);
    void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Int &anInt);
};


#endif //FISH_INT_H
