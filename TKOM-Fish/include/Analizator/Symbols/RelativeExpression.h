//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEEXPRESSION_H
#define FISH_RELATIVEEXPRESSION_H


#include "ConditionalExpression.h"
#include "ArithmeticExpression.h"
#include <Analizator/Symbol.h>


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
    //INTERPRETER
    std::reference_wrapper<Obj>object;
public:
    RelativeExpression();
    void execute(Env &env) override;
    double getDouble() const override;
    int getInt() const override;
    std::string getString() const override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
    Obj &getObject() override;
};

using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;


#endif //FISH_RELATIVEEXPRESSION_H
