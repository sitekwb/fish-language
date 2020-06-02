
//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_SIMPLESTATEMENT_H
#define FISH_SIMPLESTATEMENT_H


#include <Analizator/Symbol.h>
#include "ExpressionStatement.h"
#include "AliasStatement.h"
#include "AssignStatement.h"
#include "NewStatement.h"
#include "DeleteStatement.h"
#include "ImportStatement.h"
#include "ControlStatement.h"

class NewExpression;
using NewExpressionUP = std::unique_ptr<NewExpression>;

class ExpressionStatement;
using ExpressionStatementUP = std::unique_ptr<ExpressionStatement>;

class NewStatement;
using NewStatementUP = std::unique_ptr<NewStatement>;

class AssignStatement;
using AssignStatementUP = std::unique_ptr<AssignStatement>;


class SimpleStatement : public Symbol{
protected:
    DeleteStatementUP deleteStatement;
    ImportStatementUP importStatement;
    NewStatementUP newStatement;
    AssignStatementUP assignStatement;
    ControlStatementUP controlStatement;
    AliasStatementUP aliasStatement;
    ExpressionStatementUP expressionStatement;
public:
    SimpleStatement();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
    friend class Test;
};
using SimpleStatementUP = std::unique_ptr<SimpleStatement>;


#endif //FISH_SIMPLESTATEMENT_H
