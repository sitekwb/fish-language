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
    std::list<Object &>list;
public:
    ArithmeticExpression();
    void execute(Env &env) override;
    friend class Test;
    double getDouble() const;
    int getInt() const;
    std::string getString() const;
    bool getBool() const;
    ObjectType getObjectType() const;
    Object &getObject();
};
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;


#endif //FISH_ARITHMETICEXPRESSION_H
