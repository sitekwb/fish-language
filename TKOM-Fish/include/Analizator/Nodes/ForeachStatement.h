//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_FOREACHSTATEMENT_H
#define FISH_FOREACHSTATEMENT_H

#include "Term.h"
#include "BlockInstruction.h"
#include "Statement.h"
#include <string>

class ForeachStatement : public Statement{
protected:
    std::string idName;
    TermUP term;
    BlockInstructionUP blockInstruction;
public:
    ForeachStatement(std::string &&idName, TermUP &&term, BlockInstructionUP &&blockInstruction);

};
using ForeachStatementUP = std::unique_ptr<ForeachStatement>;


#endif //FISH_FOREACHSTATEMENT_H
