//
// Created by Wojtek on 28/05/2020.
//

#ifndef FISH_CONTROLSTATEMENT_H
#define FISH_CONTROLSTATEMENT_H

#include <string>
#include "Statement.h"
#include "ConditionalExpression.h"

class ControlStatement : public Statement{
protected:
    bool isContinue = false;
    bool isReturn = false;
    ConditionalExpressionUP returnConditionalExpression;
public:
    ControlStatement(bool isContinue);
    ControlStatement();
    ControlStatement(ConditionalExpressionUP &&returnConditionalExpression);
//    void execute(Env &env) override;
};
using ControlStatementUP = std::unique_ptr<ControlStatement>;


#endif //FISH_CONTROLSTATEMENT_H
