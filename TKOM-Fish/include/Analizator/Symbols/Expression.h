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
    //d
public:
    Expression();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;
    Object &getObject();
};
using ExpressionUP = std::unique_ptr<Expression>;

#endif //FISH_EXPRESSION_H
