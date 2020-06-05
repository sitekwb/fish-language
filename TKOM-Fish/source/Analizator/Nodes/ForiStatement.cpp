//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include <Analizator/Nodes/ForiStatement.h>

ForiStatement::ForiStatement(ArithmeticExpressionUP &&arithmeticExpression, BlockInstructionUP &&blockInstruction)
        : arithmeticExpression(move(arithmeticExpression)),
          blockInstruction(move(blockInstruction)) {

}
