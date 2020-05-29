//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ALIASSTATEMENT_H
#define FISH_ALIASSTATEMENT_H


#include <Analizator/Interpreter/Symbol.h>
#include "Type.h"

class AliasStatement : public Symbol{
protected:
    TokenUPD aliasKeyword;
    TypeUP name, type;
public:
    AliasStatement();
    void execute() override;

};
using AliasStatementUP = std::unique_ptr<AliasStatement>;


#endif //FISH_ALIASSTATEMENT_H
