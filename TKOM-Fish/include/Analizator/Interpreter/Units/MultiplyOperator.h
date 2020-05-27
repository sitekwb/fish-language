//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYOPERATOR_H
#define FISH_MULTIPLYOPERATOR_H


#include <Analizator/Interpreter/Symbol.h>

class MultiplyOperator: public Symbol{
    using MultiplyOperatorUP = std::unique_ptr<MultiplyOperator>;
protected:

public:
    void execute() override;
};


#endif //FISH_MULTIPLYOPERATOR_H
