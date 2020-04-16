//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_CONSTANT_H
#define FISH_CONSTANT_H


#include <string>
#include <ostream>
#include "../Token.h"

class Constant : public Token {

    std::string name;
public:
    explicit Constant(std::string buf);
    void print(std::ostream &os) const;
    friend std::ostream &operator<<(std::ostream &os, const Constant &constant);
};


#endif //FISH_CONSTANT_H
