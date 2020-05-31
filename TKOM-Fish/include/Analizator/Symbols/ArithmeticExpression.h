//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARITHMETICEXPRESSION_H
#define FISH_ARITHMETICEXPRESSION_H


#include <Analizator/Symbol.h>
#include "AddExpression.h"
#include "AddOperator.h"

class AddExpression;
using AddExpressionUP = std::unique_ptr<AddExpression>;

class ArithmeticExpression : public Symbol{
protected:
    AddExpressionUP addExpression;
    std::list<std::pair<AddOperatorUP, AddExpressionUP>> repeatList;
    bool isDouble;
    double doubleValue;
    int intValue;

    bool buildRepeat();
public:
    ArithmeticExpression();
    void execute() override;
    friend class Test;

};
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;


#endif //FISH_ARITHMETICEXPRESSION_H
