//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDOPERATOR_H
#define FISH_ADDOPERATOR_H


#include <Analizator/Symbol.h>

class AddOperator : public Symbol{
protected:
    TokenUPD operatorToken;
    char value;
public:
    AddOperator();
    void execute(Env &env) override;
    char getChar();
    friend class Test;

};
using AddOperatorUP = std::unique_ptr<AddOperator>;


#endif //FISH_ADDOPERATOR_H
