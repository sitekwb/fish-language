//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_EXPRESSION_H
#define FISH_EXPRESSION_H


#include <Analizator/Symbol.h>
#include "ArithmeticExpression.h"
#include "NewExpression.h"
#include "AssignExpression.h"

class Expression : public Symbol{
protected:
    ConditionalExpressionUP conditionalExpression;
    NewExpressionUP newExpression;
    AssignExpressionUP assignExpression;
public:
    Expression();
    void execute() override;
    friend class Test;
};
using ExpressionUP = std::unique_ptr<Expression>;

#endif //FISH_EXPRESSION_H
