//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Nodes/ForeachStatement.h>
#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>

using namespace std;

ForeachStatement::ForeachStatement(std::string &&idName,
                                   TermUP &&term,
                                   BlockInstructionUP &&blockInstruction)
        : idName(move(idName)),
          term(move(term)),
          blockInstruction(move(blockInstruction)) {
}
//
//void ForeachStatement::execute(Env &env) {
//    if (!constructed) {
//        return;
//    }
//
//    term->execute(env);
//    Obj &containerObject = term->getObject();
//    for (int i = 0; i < containerObject.getInt(); i++) {
//        Env localEnv = Env(env);
//        localEnv.setSymbol(identifier->getValue(), containerObject[i]);
//        try {
//            blockInstruction->execute(localEnv);
//        }
//        catch (BreakException &e) {
//            break;
//        }
//        catch (ContinueException &e) {
//
//        }
//    }
//    //done
//}
//

