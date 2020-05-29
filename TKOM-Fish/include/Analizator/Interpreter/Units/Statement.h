//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_STATEMENT_H
#define FISH_STATEMENT_H


#include <Analizator/Parser/SymbolOld.h>
#include <Analizator/Interpreter/Symbol.h>
#include "CompoundStatement.h"
#include "SimpleStatement.h"

class CompoundStatement;
using CompoundStatementUP = std::unique_ptr<CompoundStatement>;

class Statement : public Symbol {
protected:
    CompoundStatementUP compoundStatement;
    SimpleStatementUP simpleStatement;
    TokenUPD semicolonOptional;
public:
    Statement();

    void execute() override;
};

using StatementUP = std::unique_ptr<Statement>;


#endif //FISH_STATEMENT_H
