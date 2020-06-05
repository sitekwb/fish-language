//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEEXPRESSION_H
#define FISH_RELATIVEEXPRESSION_H

#include "ConditionalExpression.h"
#include "ArithmeticExpression.h"
#include <variant>

class ConditionalExpression;
using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

class ArithmeticExpression;
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;


using RelativeExpressionVariant = std::variant<ConditionalExpressionUP, ArithmeticExpressionUP>;

class RelativeExpression {
    RelativeExpressionVariant v;
public:
    RelativeExpression(RelativeExpressionVariant &&v);
};

using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;


#endif //FISH_RELATIVEEXPRESSION_H
