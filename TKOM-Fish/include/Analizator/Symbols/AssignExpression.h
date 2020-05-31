//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNEXPRESSION_H
#define FISH_ASSIGNEXPRESSION_H


#include <Analizator/Symbol.h>
#include "AssignOperator.h"
#include "Term.h"
#include "Analizator/Tokens/Identifier.h"

class AssignExpression : public Symbol{
protected:
    IdentifierUPD identifier;
    AssignOperatorUP assignOperator;
    ConditionalExpressionUP conditionalExpression;
public:
    AssignExpression();
    void execute(Env &env) override;
};
using AssignExpressionUP = std::unique_ptr<AssignExpression>;


#endif //FISH_ASSIGNEXPRESSION_H
