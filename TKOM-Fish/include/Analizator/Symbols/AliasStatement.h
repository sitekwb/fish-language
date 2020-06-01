//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ALIASSTATEMENT_H
#define FISH_ALIASSTATEMENT_H

#include "Type.h"
#include <Analizator/Symbol.h>


class AliasStatement : public Symbol{
protected:
    TokenUPD aliasKeyword;
    TypeUP name, type;
    // INTERP done
public:
    AliasStatement();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;

    friend class Test;
};
using AliasStatementUP = std::unique_ptr<AliasStatement>;


#endif //FISH_ALIASSTATEMENT_H
