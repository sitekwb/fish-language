//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDEXPRESSION_H
#define FISH_ADDEXPRESSION_H


#include "MultiplyExpression.h"
#include "MultiplyOperator.h"
#include <list>

class MultiplyExpression;
using MultiplyExpressionUP = std::unique_ptr<MultiplyExpression>;

class AddExpression {
protected:
    std::list<MultiplyExpressionUP> multiplyExpressionList;
    std::list<MultiplyOperatorUP> multiplyOperatorList;

public:
    AddExpression(std::list<MultiplyExpressionUP> &&multiplyExpressionList,
                  std::list<MultiplyOperatorUP> &&multiplyOperatorList);

};

using AddExpressionUP = std::unique_ptr<AddExpression>;


#endif //FISH_ADDEXPRESSION_H
