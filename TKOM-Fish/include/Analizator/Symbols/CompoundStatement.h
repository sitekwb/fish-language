//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_COMPOUNDSTATEMENT_H
#define FISH_COMPOUNDSTATEMENT_H


#include <Analizator/Symbol.h>
#include "IfStatement.h"
#include "WhileStatement.h"
#include "ForiStatement.h"
#include "ForeachStatement.h"
#include "ForStatement.h"


class IfStatement;
using IfStatementUP = std::unique_ptr<IfStatement>;

class WhileStatement;
using WhileStatementUP = std::unique_ptr<WhileStatement>;

class ForeachStatement;
using ForeachStatementUP = std::unique_ptr<ForeachStatement>;

class ForStatement;
using ForStatementUP = std::unique_ptr<ForStatement>;

class ForiStatement;
using ForiStatementUP = std::unique_ptr<ForiStatement>;


class CompoundStatement : public Symbol{
protected:
    IfStatementUP ifStatement;
    WhileStatementUP whileStatement;
    ForStatementUP forStatement;
    ForiStatementUP foriStatement;
    ForeachStatementUP foreachStatement;
public:
    CompoundStatement();
    void execute(Env &env) override;
    ObjectType getObjectType()const override;

};
using CompoundStatementUP = std::unique_ptr<CompoundStatement>;

#endif //FISH_COMPOUNDSTATEMENT_H
