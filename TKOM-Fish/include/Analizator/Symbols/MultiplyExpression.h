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
public:
    MultiplyExpression();
    void execute(Env &env) override;
    int getInt() const override;
    double getDouble() const override;
    std::string getString() const override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using MultiplyExpressionUP = std::unique_ptr<MultiplyExpression>;


#endif //FISH_MULTIPLYEXPRESSION_H
