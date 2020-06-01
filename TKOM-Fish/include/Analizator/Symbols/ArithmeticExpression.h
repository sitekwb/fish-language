//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARITHMETICEXPRESSION_H
#define FISH_ARITHMETICEXPRESSION_H


#include <Analizator/Symbol.h>
#include "AddExpression.h"
#include "AddOperator.h"

class AddExpression;
using AddExpressionUP = std::unique_ptr<AddExpression>;

class ArithmeticExpression : public Symbol{
protected:
    AddExpressionUP addExpression;
    std::list<std::pair<AddOperatorUP, AddExpressionUP>> repeatList;

    bool buildRepeat();
    //INTERPRETER done
    std::list<std::reference_wrapper<Obj>>list;
public:
    ArithmeticExpression();
    void execute(Env &env) override;
    friend class Test;
    double getDouble() const override;
    int getInt() const override;
    std::string getString() const override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
    Obj &getObject() override;
};
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;


#endif //FISH_ARITHMETICEXPRESSION_H
