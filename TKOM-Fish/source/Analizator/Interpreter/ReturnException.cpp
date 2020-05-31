//
// Created by Wojtek on 31/05/2020.
//

#include "Analizator/Interpreter/ReturnException.h"

ReturnException::ReturnException(ConditionalExpressionUP &conditionalExpression_)
        : conditionalExpression(conditionalExpression_) {

}

ConditionalExpressionUP &ReturnException::getReturnObject() {
    return conditionalExpression;
}
