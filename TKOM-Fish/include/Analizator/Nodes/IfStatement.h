//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IFSTATEMENT_H
#define FISH_IFSTATEMENT_H

#include "Statement.h"
#include "ConditionalExpression.h"
#include "BlockInstruction.h"

class IfStatement : public Statement{
protected:
    ConditionalExpressionUP conditionalExpression;
    BlockInstructionUP blockInstruction, elseBlockInstruction;
public:
    IfStatement(ConditionalExpressionUP &&conditionalExpression,
            BlockInstructionUP &&blockInstruction,
                BlockInstructionUP &&elseBlockInstruction);

//    void execute(Env &env) override;
};
using IfStatementUP = std::unique_ptr<IfStatement>;

#endif //FISH_IFSTATEMENT_H
