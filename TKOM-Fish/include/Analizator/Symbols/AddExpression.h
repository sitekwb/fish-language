//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ADDEXPRESSION_H
#define FISH_ADDEXPRESSION_H


#include <Analizator/Symbol.h>
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
    void execute(Env &env) override;
    bool isDoubleValue();
    bool getDouble();
    bool getInt();
    virtual SymbolType getType();

    friend class Test;
};
using AddExpressionUP = std::unique_ptr<AddExpression>;


#endif //FISH_ADDEXPRESSION_H
