//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ALIASSTATEMENT_H
#define FISH_ALIASSTATEMENT_H

#include "Statement.h"
#include <string>


class AliasStatement : public Statement{
protected:
    std::string aliasType, type;
public:
    AliasStatement(std::string &&aliasType, std::string &&type);
//    void execute(Env &env) override;
};
using AliasStatementUP = std::unique_ptr<AliasStatement>;


#endif //FISH_ALIASSTATEMENT_H
