//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_IFSTATEMENT_H
#define FISH_IFSTATEMENT_H


#include <Analizator/Symbol.h>
#include "ConditionalExpression.h"
#include "BlockInstruction.h"

class BlockInstruction;
using BlockInstructionUP = std::unique_ptr<BlockInstruction>;

class IfStatement : public Symbol{
protected:
    TokenUPD ifToken;
    TokenUPD bracketOpen;
    ConditionalExpressionUP conditionalExpression;
    TokenUPD  bracketClose;
    BlockInstructionUP blockInstruction;
    TokenUPD elseOptional;
    BlockInstructionUP elseBlockInstruction;
public:
    IfStatement();
    void execute(Env &env) override;
};
using IfStatementUP = std::unique_ptr<IfStatement>;

#endif //FISH_IFSTATEMENT_H
