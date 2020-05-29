//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FOREACHSTATEMENT_H
#define FISH_FOREACHSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>
#include "ListIdentifier.h"
#include "BlockInstruction.h"

class ForeachStatement : public Symbol{
protected:
    TokenUPD foreachToken;
    TokenUPD bracketOpen;
    IdentifierUPD identifier;
    TokenUPD inToken;
    ListIdentifierUP listIdentifier;
    TokenUPD bracketClose;
    BlockInstructionUP blockInstruction;
public:
    ForeachStatement();
    void execute() override;
};
using ForeachStatementUP = std::unique_ptr<ForeachStatement>;


#endif //FISH_FOREACHSTATEMENT_H
