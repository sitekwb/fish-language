//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_BLOCKINSTRUCTION_H
#define FISH_BLOCKINSTRUCTION_H


#include <Analizator/Symbol.h>
#include "Statement.h"

class Statement;
using StatementUP = std::unique_ptr<Statement>;

class BlockInstruction : public Symbol{
protected:
    TokenUPD blockOpen;
    std::list<StatementUP>statementList;
    TokenUPD blockClose;
public:
    BlockInstruction();
    void execute(Env &env) override;

};
using BlockInstructionUP = std::unique_ptr<BlockInstruction>;

#endif //FISH_BLOCKINSTRUCTION_H
