//
// Created by Wojtek on 27/05/2020.
//

#include <memory>
#include <Analizator/Nodes/IfStatement.h>

//
//void IfStatement::execute(Env &env) {
//    Env localEnv(env);
//    conditionalExpression->execute(localEnv);
//    if (conditionalExpression->getBool()) {
//        blockInstruction->execute(localEnv);
//    } else if (elseOptional) {
//        Env elseEnv(env);
//        elseBlockInstruction->execute(elseEnv);
//    }
//}


IfStatement::IfStatement(ConditionalExpressionUP &&conditionalExpression,
                         BlockInstructionUP &&blockInstruction,
                         BlockInstructionUP &&elseBlockInstruction)
        : conditionalExpression(move(conditionalExpression)),
          blockInstruction(move(blockInstruction)),
          elseBlockInstruction(move(elseBlockInstruction)) {

}
