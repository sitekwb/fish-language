//
// Created by Wojtek on 31/05/2020.
//

#ifndef FISH_RETURNEXCEPTION_H
#define FISH_RETURNEXCEPTION_H


#include <Analizator/Symbols/ConditionalExpression.h>

class ReturnException : std::exception{
    ConditionalExpressionUP &conditionalExpression;
public:
    ReturnException(ConditionalExpressionUP &conditionalExpression);
    ConditionalExpressionUP &getReturnObject();
};


#endif //FISH_RETURNEXCEPTION_H
