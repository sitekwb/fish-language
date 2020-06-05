//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include <Analizator/Nodes/WhileStatement.h>

//
//void WhileStatement::execute(Env &env) {
//    Env serviceEnv(env);
//    conditionalExpression->execute(serviceEnv);
//    while (conditionalExpression->getBool()) {
//        Env localEnv(serviceEnv);
//        try {
//            blockInstruction->execute(localEnv);
//        }
//        catch (BreakException &e) {
//            break;
//        }
//        catch (ContinueException &e) {
//
//        }
//        conditionalExpression->execute(serviceEnv);
//    }
//    //done
//}

WhileStatement::WhileStatement(ConditionalExpressionUP &&conditionalExpression_, BlockInstructionUP &&blockInstruction_)
        : conditionalExpression(move(conditionalExpression_)), blockInstruction(move(blockInstruction_)) {

}

