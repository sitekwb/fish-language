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
public:
    Argument();
    void execute() override;
    friend class Test;

};
using ArgumentUP = std::unique_ptr<Argument>;


#endif //FISH_ARGUMENT_H
