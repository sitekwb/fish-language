//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ANDEXPRESSION_H
#define FISH_ANDEXPRESSION_H


#include "OrExpression.h"
#include <memory>

class OrExpression;
using OrExpressionUP = std::unique_ptr<OrExpression>;

class AndExpression {
protected:
    std::list<OrExpressionUP> orExpressionList;
public:
    AndExpression(std::list<OrExpressionUP> &&orExpressionList);

//    void execute(Env &env);
};

using AndExpressionUP = std::unique_ptr<AndExpression>;
#endif //FISH_ANDEXPRESSION_H
