//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/Units/ArithmeticExpression.h>
#include "Analizator/Interpreter/Units/RelativeExpression.h"

RelativeExpression::RelativeExpression() {
    constructed = buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose);
    if(!constructed) {
        bracketOpen.reset();
        conditionalExpression.reset();
        bracketClose.reset();

        constructed = buildSymbol<ArithmeticExpression>(arithmeticExpression);
    }
}

void RelativeExpression::execute() {
//TODO
}

double RelativeExpression::getValue() {
    //TODO
    return 0;
}
