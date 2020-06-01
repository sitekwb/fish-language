//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_OREXPRESSION_H
#define FISH_OREXPRESSION_H


#include <Analizator/Symbol.h>
#include "UnaryNot.h"
#include "RelativeExpression.h"
#include "RelativeOperator.h"

class OrExpression;
using OrExpressionUP = std::unique_ptr<OrExpression>;

class RelativeExpression;
using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;

class OrExpression : public Symbol{
protected:
    UnaryNotUP unaryNotOptional;
    RelativeExpressionUP relativeExpression;
    std::list<std::tuple<RelativeOperatorUP, UnaryNotUP, RelativeExpressionUP>> repeatList;

    bool buildRepeat();
    //INTERPRETER
    std::list<std::reference_wrapper<Obj>>objectList;
public:
    OrExpression();
    void execute(Env &env) override;
    double getDouble() const override;
    int getInt() const override;
    std::string getString() const override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
    Obj &getObject() override;
};
using OrExpressionUP = std::unique_ptr<OrExpression>;


#endif //FISH_OREXPRESSION_H
