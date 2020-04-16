//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_STR_H
#define FISH_STR_H


#include <string>
#include <list>
#include <ostream>
#include "ConstantValue.h"

class Str : public ConstantValue {
    std::string value;
public:
    explicit Str(std::string val);
    void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Str &str);
};


#endif //FISH_STR_H
