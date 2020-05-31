//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FOREACHSTATEMENT_H
#define FISH_FOREACHSTATEMENT_H


#include <Analizator/Symbol.h>
#include "BlockInstruction.h"

class Term;
using TermUP = std::unique_ptr<Term>;

class ForeachStatement : public Symbol{
protected:
    TokenUPD foreachToken;
    TokenUPD bracketOpen;
    IdentifierUPD identifier;
    TokenUPD inToken;
    TermUP term;
    TokenUPD bracketClose;
    BlockInstructionUP blockInstruction;
public:
    ForeachStatement();
    void execute(Env &env) override;
};
using ForeachStatementUP = std::unique_ptr<ForeachStatement>;


#endif //FISH_FOREACHSTATEMENT_H
