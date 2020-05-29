//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_EXPRESSION_H
#define FISH_EXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>
#include "ArithmeticExpression.h"
#include "NewExpression.h"

class Expression : public Symbol{
protected:
    ArithmeticExpressionUP arithmeticExpression;
    NewExpressionUP newExpression;
public:
    Expression();
    void execute() override;
};
using ExpressionUP = std::unique_ptr<Expression>;

#endif //FISH_EXPRESSION_H
