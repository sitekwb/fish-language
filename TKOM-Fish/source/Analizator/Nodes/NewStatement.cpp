//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/NewStatement.h>

using namespace std;

NewStatement::NewStatement(bool mutBool, bool staticBool, std::string &&typeName, std::string &&idName,
                           ArgumentListUP &&argumentList, AssignOperatorUP &&assignOperator,
                           ConditionalExpressionUP &&conditionalExpression)
        : mutBool(mutBool),
          staticBool(staticBool),
          typeName(move(typeName)),
          idName(move(idName)),
          argumentList(move(argumentList)),
          assignOperator(move(assignOperator)),
          conditionalExpression(move(conditionalExpression)) {

}
