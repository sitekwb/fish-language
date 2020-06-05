//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_NEWSTATEMENT_H
#define FISH_NEWSTATEMENT_H

#include "Expression.h"
#include "ArgumentList.h"
#include "AssignOperator.h"
#include "ConditionalExpression.h"
#include "ClassDefinition.h"


class NewStatement : public Expression {
protected:
    bool mutBool;
    bool staticBool;
    std::string typeName;
    std::string idName;
    ArgumentListUP argumentList;
    AssignOperatorUP assignOperator;
    ConditionalExpressionUP conditionalExpression;
public:
    NewStatement(bool mutBool, bool staticBool,
                 std::string &&typeName, std::string &&idName,
                 ArgumentListUP &&argumentList, AssignOperatorUP &&assignOperator,
                 ConditionalExpressionUP &&conditionalExpression);
};

using NewExpressionUP = std::unique_ptr<NewStatement>;

#endif //FISH_NEWSTATEMENT_H
