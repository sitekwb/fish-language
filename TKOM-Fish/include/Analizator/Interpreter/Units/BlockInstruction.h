//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_BLOCKINSTRUCTION_H
#define FISH_BLOCKINSTRUCTION_H


#include <Analizator/Interpreter/Symbol.h>

class BlockInstruction : public Symbol{
    using BlockInstructionUP = std::unique_ptr<BlockInstruction>;
protected:

public:
    void execute() override;
};

#endif //FISH_BLOCKINSTRUCTION_H
