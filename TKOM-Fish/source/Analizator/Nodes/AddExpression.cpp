//
// Created by Wojtek on 27/05/2020.
//


#include <Analizator/Nodes/AddExpression.h>

using namespace std;

AddExpression::AddExpression(std::list<MultiplyExpressionUP> &&multiplyExpressionList,
                             std::list<MultiplyOperatorUP> &&multiplyOperatorList)
        : multiplyOperatorList(move(multiplyOperatorList)),
          multiplyExpressionList(move(multiplyExpressionList)) {

}
