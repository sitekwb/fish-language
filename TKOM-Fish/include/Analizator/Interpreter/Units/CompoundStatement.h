//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_COMPOUNDSTATEMENT_H
#define FISH_COMPOUNDSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class CompoundStatement : public Symbol{
    using CompoundStatementUP = std::unique_ptr<CompoundStatement>;
protected:

public:
    void execute() override;
};

#endif //FISH_COMPOUNDSTATEMENT_H
