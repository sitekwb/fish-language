//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORSTATEMENT_H
#define FISH_FORSTATEMENT_H

#include "Expression.h"
#include "ConditionalExpression.h"
#include "BlockInstruction.h"

class ForStatement : public Statement {
protected:
    StatementUP expressionOptional;
    ConditionalExpressionUP conditionalExpression;
    StatementUP expression2Optional;
    BlockInstructionUP blockInstruction;
public:
    ForStatement(StatementUP &&expression,
                 ConditionalExpressionUP &&conditionalExpression,
                 StatementUP &&expression2,
                 BlockInstructionUP &&blockInstruction);
};

using ForStatementUP = std::unique_ptr<ForStatement>;

#endif //FISH_FORSTATEMENT_H
