//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEEXPRESSION_H
#define FISH_RELATIVEEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>
#include "ConditionalExpression.h"
#include "ArithmeticExpression.h"


class ConditionalExpression;
using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

class ArithmeticExpression;
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;


class RelativeExpression : public Symbol {
protected:
    TokenUPD bracketOpen;
    ConditionalExpressionUP conditionalExpression;
    TokenUPD bracketClose;
    ArithmeticExpressionUP arithmeticExpression;
public:
    RelativeExpression();
    void execute() override;
    double getValue();
};

using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;


#endif //FISH_RELATIVEEXPRESSION_H
