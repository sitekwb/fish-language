//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORISTATEMENT_H
#define FISH_FORISTATEMENT_H

#include "UnsignedIntTerm.h"
#include <Analizator/Symbol.h>
#include "BlockInstruction.h"

class ForiStatement : public Symbol{
protected:
    TokenUPD foriToken;
    TokenUPD bracketOpen;
    UnsignedIntTermUP unsignedIntTerm;
    TokenUPD bracketClose;
    BlockInstructionUP blockInstruction;
public:
    ForiStatement();
    void execute(Env &env) override;
};
using ForiStatementUP = std::unique_ptr<ForiStatement>;

#endif //FISH_FORISTATEMENT_H
