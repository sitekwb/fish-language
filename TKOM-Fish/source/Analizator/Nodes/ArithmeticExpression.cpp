//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/ArithmeticExpression.h>


using namespace std;

ArithmeticExpression::ArithmeticExpression(std::list<AddExpressionUP> &&addExpressionList,
                                           std::list<AddOperatorUP> &&addOperatorList)
        : addExpressionList(move(addExpressionList)),
          addOperatorList(move(addOperatorList)) {

}
