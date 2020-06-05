//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_CONDITIONALEXPRESSION_H
#define FISH_CONDITIONALEXPRESSION_H

#include "Expression.h"
#include "AndExpression.h"
#include <list>
#include <memory>

class AndExpression;
using AndExpressionUP = std::unique_ptr<AndExpression>;

class ConditionalExpression : public Expression{
    std::list<AndExpressionUP> andExpressionList;
public:
    ConditionalExpression(std::list<AndExpressionUP> &&andExpressionList);

//    void execute(Env &env);
};

using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

#endif //FISH_CONDITIONALEXPRESSION_H
