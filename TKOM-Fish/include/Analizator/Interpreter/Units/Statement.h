//
// Created by Wojtek on 26/05/2020.
//

#ifndef FISH_STATEMENT_H
#define FISH_STATEMENT_H


#include <Analizator/Parser/SymbolOld.h>
#include <Analizator/Interpreter/Symbol.h>

class Statement: public Symbol{
    using StatementUP = std::unique_ptr<Statement>;
protected:

public:
    void execute() override;
};


#endif //FISH_STATEMENT_H
