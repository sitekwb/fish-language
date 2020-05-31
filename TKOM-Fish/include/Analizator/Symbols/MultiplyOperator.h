//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYOPERATOR_H
#define FISH_MULTIPLYOPERATOR_H


#include <Analizator/Symbol.h>

class MultiplyOperator: public Symbol{
protected:
    TokenUPD operatorToken;
    char value;

public:
    MultiplyOperator();
    void execute() override;
    char getChar();
};
using MultiplyOperatorUP = std::unique_ptr<MultiplyOperator>;


#endif //FISH_MULTIPLYOPERATOR_H
