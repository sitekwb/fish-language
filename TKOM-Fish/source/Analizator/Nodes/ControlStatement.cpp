//
// Created by Wojtek on 28/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include <Analizator/Nodes/ControlStatement.h>

#include "Analizator/Nodes/ControlStatement.h"

using namespace std;

ControlStatement::ControlStatement(bool isContinue)
        : isContinue(isContinue) {

}

ControlStatement::ControlStatement()
        : isReturn(true) {

}

ControlStatement::ControlStatement(ConditionalExpressionUP &&returnConditionalExpression)
        : isReturn(true),
          returnConditionalExpression(move(returnConditionalExpression)) {

}



//
//void ControlStatement::execute(Env &env) {
//    if (!constructed) {
//        return;
//    }
//    if (controlToken->getValue() == "break") {
//        throw BreakException();
//    }
//    if (controlToken->getValue() == "continue") {
//        throw ContinueException();
//    }
//    if(conditionalExpressionOptional){
//        conditionalExpressionOptional->execute(env);
//
//    }
//    throw ReturnException(conditionalExpressionOptional);
//}


