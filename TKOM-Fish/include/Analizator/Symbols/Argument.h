//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ARGUMENT_H
#define FISH_ARGUMENT_H


#include <Analizator/Symbol.h>
#include "ConditionalExpression.h"

class ConditionalExpression;
using ConditionalExpressionUP = std::unique_ptr<ConditionalExpression>;

class Argument: public Symbol{
protected:
    ConditionalExpressionUP conditionalExpression;
    //INTERP done
public:
    Argument();
    void execute(Env &env) override;
    friend class Test;
    ObjectType getObjectType() const override;
};
using ArgumentUP = std::unique_ptr<Argument>;


#endif //FISH_ARGUMENT_H
