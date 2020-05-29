//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_OREXPRESSION_H
#define FISH_OREXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>
#include "UnaryNot.h"
#include "RelativeExpression.h"
#include "RelativeOperator.h"

class OrExpression;
using OrExpressionUP = std::unique_ptr<OrExpression>;

class OrExpression : public Symbol{
protected:
    UnaryNotUP unaryNotOptional;
    RelativeExpressionUP relativeExpression;
    std::list<std::tuple<RelativeOperatorUP, UnaryNotUP, RelativeExpressionUP>> repeatList;

    bool value;
    bool buildRepeat();
public:
    OrExpression();
    void execute() override;
    bool getValue();
};
using OrExpressionUP = std::unique_ptr<OrExpression>;


#endif //FISH_OREXPRESSION_H
