//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_TYPE_H
#define FISH_TYPE_H


#include <string>
#include <ostream>
#include "../Token.h"

class Type : public Token{
    std::string name;
public:
    explicit Type(std::string name_);
    virtual void print(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Type &type);
};


#endif //FISH_TYPE_H
