//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORISTATEMENT_H
#define FISH_FORISTATEMENT_H

#include "Statement.h"
#include "BlockInstruction.h"
#include "ArithmeticExpression.h"


class ForiStatement : public Statement{
protected:
    ArithmeticExpressionUP arithmeticExpression;
    BlockInstructionUP blockInstruction;
public:
    ForiStatement(ArithmeticExpressionUP &&arithmeticExpression, BlockInstructionUP &&blockInstruction);
};
using ForiStatementUP = std::unique_ptr<ForiStatement>;

#endif //FISH_FORISTATEMENT_H
