//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARITHMETICEXPRESSION_H
#define FISH_ARITHMETICEXPRESSION_H


#include "AddExpression.h"
#include "AddOperator.h"
#include <list>
#include <memory>

class AddExpression;
using AddExpressionUP = std::unique_ptr<AddExpression>;

class ArithmeticExpression {
protected:
    std::list<AddExpressionUP> addExpressionList;
    std::list<AddOperatorUP> addOperatorList;
public:
    ArithmeticExpression(std::list<AddExpressionUP> &&addExpressionList,
            std::list<AddOperatorUP> &&addOperatorList);
};
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;


#endif //FISH_ARITHMETICEXPRESSION_H
