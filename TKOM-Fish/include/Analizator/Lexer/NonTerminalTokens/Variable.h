//
// Created by Wojtek on 15/04/2020.
//

#ifndef FISH_VARIABLE_H
#define FISH_VARIABLE_H


#include <string>
#include <ostream>
#include "../Token.h"

class Variable : public Token {
    std::string name;
public:
    explicit Variable(std::string name_);
    virtual void print(std::ostream &os) const;
    friend std::ostream &operator<<(std::ostream &os, const Variable &variable);
};


#endif //FISH_VARIABLE_H
