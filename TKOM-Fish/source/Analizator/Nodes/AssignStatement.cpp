//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Nodes/AssignStatement.h"

using namespace std;

AssignStatement::AssignStatement(std::string &&idName,
                                 AssignOperatorUP &&assignOperator,
                                 ConditionalExpressionUP &&conditionalExpression)
        : idName(move(idName)),
          assignOperator(move(assignOperator)),
          conditionalExpression(move(conditionalExpression)) {

}
