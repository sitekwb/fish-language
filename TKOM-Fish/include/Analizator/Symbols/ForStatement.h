//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORSTATEMENT_H
#define FISH_FORSTATEMENT_H


#include <Analizator/Symbol.h>
#include "Expression.h"
#include "ConditionalExpression.h"
#include "BlockInstruction.h"

class ForStatement : public Symbol{
protected:
    TokenUPD forToken;
    TokenUPD bracketOpen;
    ExpressionUP expression1Optional;
    TokenUPD semicolon1;
    ConditionalExpressionUP conditionalExpression;
    TokenUPD semicolon2;
    ExpressionUP expression2Optional;
    TokenUPD bracketClose;
    BlockInstructionUP blockInstruction;
public:
    ForStatement();
    void execute() override;
};
using ForStatementUP = std::unique_ptr<ForStatement>;

#endif //FISH_FORSTATEMENT_H
