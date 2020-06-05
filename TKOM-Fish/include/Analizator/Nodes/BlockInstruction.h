//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_BLOCKINSTRUCTION_H
#define FISH_BLOCKINSTRUCTION_H


#include "Statement.h"
#include <list>

class BlockInstruction {
protected:
    std::list<StatementUP> statementList;
public:
    BlockInstruction(std::list<StatementUP> &&statementList);

//    void execute(Env &env);
};

using BlockInstructionUP = std::unique_ptr<BlockInstruction>;

#endif //FISH_BLOCKINSTRUCTION_H
