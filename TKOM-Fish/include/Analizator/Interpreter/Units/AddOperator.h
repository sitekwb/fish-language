//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDOPERATOR_H
#define FISH_ADDOPERATOR_H


#include <Analizator/Interpreter/Symbol.h>

class AddOperator : public Symbol{
    using AddOperatorUP = std::unique_ptr<AddOperator>;
protected:

public:
    void execute() override;
};


#endif //FISH_ADDOPERATOR_H
