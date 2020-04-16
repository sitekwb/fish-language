//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_CONSTANTVALUE_H
#define FISH_CONSTANTVALUE_H


#include <ostream>
#include "../Token.h"

class ConstantValue : public Token {
public:
    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const ConstantValue &value);
};


#endif //FISH_CONSTANTVALUE_H
