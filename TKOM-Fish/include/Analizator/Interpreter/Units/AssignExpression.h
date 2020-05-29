//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNEXPRESSION_H
#define FISH_ASSIGNEXPRESSION_H


#include <Analizator/Interpreter/Symbol.h>
#include "AssignOperator.h"
#include "Term.h"
#include "Analizator/Interpreter/Identifier.h"

class AssignExpression : public Symbol{
protected:
    IdentifierUPD identifier;
    AssignOperatorUP assignOperator;
    TermUP term;
public:
    AssignExpression();
    void execute() override;
};
using AssignExpressionUP = std::unique_ptr<AssignExpression>;


#endif //FISH_ASSIGNEXPRESSION_H
