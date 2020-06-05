//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYEXPRESSION_H
#define FISH_MULTIPLYEXPRESSION_H


#include "Term.h"
#include <list>

class Term;
using TermUP = std::unique_ptr<Term>;

class MultiplyExpression {
protected:
    bool unaryMinus;
    TermUP term;
public:
    MultiplyExpression(bool unaryMinus, TermUP &&term);
};
using MultiplyExpressionUP = std::unique_ptr<MultiplyExpression>;


#endif //FISH_MULTIPLYEXPRESSION_H
