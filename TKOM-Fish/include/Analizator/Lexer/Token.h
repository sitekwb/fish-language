//
// Created by Wojtek on 14/04/2020.
//

#ifndef FISH_TOKEN_H
#define FISH_TOKEN_H


#include <ostream>

class Token {
public:

    bool operator==(const Token &rhs) const;

    bool operator!=(const Token &rhs) const;

    virtual void print(std::ostream &os) const = 0;

    friend std::ostream &operator<<(std::ostream &os, const Token &token);
};


#endif //FISH_TOKEN_H
