//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include <Analizator/Nodes/ForStatement.h>

using namespace std;

ForStatement::ForStatement(StatementUP &&expression,
                           ConditionalExpressionUP &&conditionalExpression,
                           StatementUP &&expression2,
                           BlockInstructionUP &&blockInstruction)
        : expressionOptional(move(expression)),
          conditionalExpression(move(conditionalExpression)),
          expression2Optional(move(expression2)),
          blockInstruction(move(blockInstruction)) {

}
