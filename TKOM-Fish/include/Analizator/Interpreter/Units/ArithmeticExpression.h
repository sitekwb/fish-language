//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARITHMETICEXPRESSION_H
#define FISH_ARITHMETICEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>

class ArithmeticExpression : public Symbol{
    using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;
protected:

public:
    void execute() override;
};


#endif //FISH_ARITHMETICEXPRESSION_H
