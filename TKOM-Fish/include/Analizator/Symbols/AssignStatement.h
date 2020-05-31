//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNSTATEMENT_H
#define FISH_ASSIGNSTATEMENT_H


#include <Analizator/Symbol.h>
#include "AssignExpression.h"

class AssignStatement : public Symbol{
protected:
    AssignExpressionUP assignExpression;
public:
    AssignStatement();
    void execute() override;
};
using AssignStatementUP = std::unique_ptr<AssignStatement>;

#endif //FISH_ASSIGNSTATEMENT_H
