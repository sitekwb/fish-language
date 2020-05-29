//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FORISTATEMENT_H
#define FISH_FORISTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>
#include "UnsignedIntTerm.h"
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
    void execute() override;
};
using ForiStatementUP = std::unique_ptr<ForiStatement>;

#endif //FISH_FORISTATEMENT_H
