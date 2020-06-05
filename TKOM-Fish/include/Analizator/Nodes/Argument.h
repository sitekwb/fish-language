//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENT_H
#define FISH_ARGUMENT_H


#include "ConditionalExpression.h"
#include <memory>

class ConditionalExpression;
using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

class Argument {
protected:
    ConditionalExpressionUP conditionalExpression;
public:
    Argument(ConditionalExpressionUP &&conditionalExpression);
};
using ArgumentUP = std::unique_ptr<Argument>;


#endif //FISH_ARGUMENT_H
