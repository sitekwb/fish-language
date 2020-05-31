//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_WHILESTATEMENT_H
#define FISH_WHILESTATEMENT_H


#include <Analizator/Symbol.h>
#include "ConditionalExpression.h"
#include "BlockInstruction.h"

class BlockInstruction;
using BlockInstructionUP = std::unique_ptr<BlockInstruction>;


class WhileStatement : public Symbol{
protected:
    TokenUPD whileToken, bracketOpen;
    ConditionalExpressionUP conditionalExpression;
    TokenUPD bracketClose;
    BlockInstructionUP blockInstruction;
public:
    WhileStatement();
    void execute(Env &env) override;
};
using WhileStatementUP = std::unique_ptr<WhileStatement>;


#endif //FISH_WHILESTATEMENT_H
