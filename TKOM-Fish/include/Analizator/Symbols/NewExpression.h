//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_NEWEXPRESSION_H
#define FISH_NEWEXPRESSION_H


#include <Analizator/Symbol.h>
#include "Type.h"
#include "ArgumentList.h"
#include "AssignOperator.h"
#include "ConditionalExpression.h"

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
    FunctionCallUP constructorCall;
public:
    NewExpression();
    void execute(Env &env) override;
};
using NewExpressionUP = std::unique_ptr<NewExpression>;

#endif //FISH_NEWEXPRESSION_H
