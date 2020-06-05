//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_WHILESTATEMENT_H
#define FISH_WHILESTATEMENT_H

#include "ConditionalExpression.h"
#include "BlockInstruction.h"
#include "Statement.h"

class WhileStatement : public Statement {
protected:
    ConditionalExpressionUP conditionalExpression;
    BlockInstructionUP blockInstruction;
public:
    WhileStatement(ConditionalExpressionUP &&conditionalExpression, BlockInstructionUP &&blockInstruction);
//    void execute(Env &env) override;
};

using WhileStatementUP = std::unique_ptr<WhileStatement>;


#endif //FISH_WHILESTATEMENT_H
