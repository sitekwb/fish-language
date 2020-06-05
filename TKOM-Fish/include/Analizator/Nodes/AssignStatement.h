//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNSTATEMENT_H
#define FISH_ASSIGNSTATEMENT_H


#include "AssignOperator.h"
#include "ConditionalExpression.h"
#include "Expression.h"

enum class AssignOperator;
using AssignOperatorUP = std::unique_ptr<AssignOperator>;

class AssignStatement : public Expression{
protected:
    std::string idName;
    AssignOperatorUP assignOperator;
    ConditionalExpressionUP conditionalExpression;
public:
    AssignStatement(std::string &&idName, AssignOperatorUP &&assignOperator,
                    ConditionalExpressionUP &&conditionalExpression);
};
using AssignStatementUP = std::unique_ptr<AssignStatement>;


#endif //FISH_ASSIGNSTATEMENT_H
