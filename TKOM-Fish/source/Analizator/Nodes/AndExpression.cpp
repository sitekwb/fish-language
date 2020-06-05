//
// Created by Wojtek on 27/05/2020.
//

#include <list>
#include <Analizator/Nodes/AndExpression.h>

using namespace std;


AndExpression::AndExpression(std::list <OrExpressionUP> &&orExpressionList)
: orExpressionList(move(orExpressionList)) {}
