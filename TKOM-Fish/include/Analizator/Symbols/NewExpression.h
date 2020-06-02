//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_NEWEXPRESSION_H
#define FISH_NEWEXPRESSION_H

#include "Type.h"
#include "ArgumentList.h"
#include "AssignOperator.h"
#include "ConditionalExpression.h"
#include "ClassDefinition.h"
#include <Analizator/Symbol.h>

class ClassDefinition;
using ClassDefinitionUP = std::unique_ptr<ClassDefinition>;

class NewExpression : public Symbol{
protected:
    TokenUPD newToken;
    TokenUPD mutTokenOptional;
    TokenUPD staticTokenOptional;
    TypeUP typeOptional;
    IdentifierUPD identifier;
    TokenUPD constant;
    TokenUPD bracketOpenOptional;
    ArgumentListUP argumentListOptional;
    TokenUPD bracketCloseOptional;
    AssignOperatorUP assignOperatorOptional;
    ConditionalExpressionUP conditionalExpression;

    void buildTypeAndId();

    //INTERPRETER
    ClassDefinitionUP classDefinitionObject;
public:
    NewExpression();
    void execute(Env &env) override;
    ObjectType getObjectType() const override;
};
using NewExpressionUP = std::unique_ptr<NewExpression>;

#endif //FISH_NEWEXPRESSION_H
