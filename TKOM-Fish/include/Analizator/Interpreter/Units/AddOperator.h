//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDOPERATOR_H
#define FISH_ADDOPERATOR_H


#include <Analizator/Interpreter/Symbol.h>

class AddOperator : public Symbol{
protected:
    TokenUPD operatorToken;
    char value;
public:
    AddOperator();
    void execute() override;
    char getChar();

};
using AddOperatorUP = std::unique_ptr<AddOperator>;


#endif //FISH_ADDOPERATOR_H
