//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ALIASSTATEMENT_H
#define FISH_ALIASSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>

class AliasStatement : public Symbol{
    using AliasStatementUP = std::unique_ptr<AliasStatement>;
protected:

public:
    void execute() override;
};


#endif //FISH_ALIASSTATEMENT_H
