//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDEXPRESSION_H
#define FISH_ADDEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>
#include "MultiplyExpression.h"
#include "MultiplyOperator.h"

class MultiplyExpression;
using MultiplyExpressionUP = std::unique_ptr<MultiplyExpression>;

class AddExpression : public Symbol{
protected:
    MultiplyExpressionUP multiplyExpression;
    std::list<std::pair<MultiplyOperatorUP, MultiplyExpressionUP>> repeatList;
    bool isDouble;
    double doubleValue;
    int intValue;

    bool buildRepeat();
public:
    AddExpression();
    void execute() override;
    bool isDoubleValue();
    bool getDouble();
    bool getInt();
};
using AddExpressionUP = std::unique_ptr<AddExpression>;


#endif //FISH_ADDEXPRESSION_H
