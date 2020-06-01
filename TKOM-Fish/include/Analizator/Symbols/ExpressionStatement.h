//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_EXPRESSIONSTATEMENT_H
#define FISH_EXPRESSIONSTATEMENT_H


#include <Analizator/Symbol.h>
#include "Expression.h"

class Expression;
using ExpressionUP = std::unique_ptr<Expression>;

class ExpressionStatement : public Symbol{
protected:
    ExpressionUP expression;
    //d
public:
    ExpressionStatement();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using ExpressionStatementUP = std::unique_ptr<ExpressionStatement>;

#endif //FISH_EXPRESSIONSTATEMENT_H
