//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYEXPRESSION_H
#define FISH_MULTIPLYEXPRESSION_H


#include <Analizator/Symbol.h>
#include "UnarySign.h"
#include "Term.h"

class Term;
using TermUP = std::unique_ptr<Term>;

class MultiplyExpression : public Symbol{
protected:
    UnarySignUP unarySignOptional;
    TermUP term;

    bool isDouble;
    double doubleValue;
    int intValue;
public:
    MultiplyExpression();
    void execute() override;
    bool isDoubleValue();
    double getDouble();
    int getInt();
    friend class Test;
};
using MultiplyExpressionUP = std::unique_ptr<MultiplyExpression>;


#endif //FISH_MULTIPLYEXPRESSION_H
