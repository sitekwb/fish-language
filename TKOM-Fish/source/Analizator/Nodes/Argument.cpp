//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/Argument.h>


Argument::Argument(ConditionalExpressionUP &&conditionalExpression)
        : conditionalExpression(move(conditionalExpression)) {

}
