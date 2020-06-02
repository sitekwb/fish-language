//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include "Analizator/Symbols/WhileStatement.h"

WhileStatement::WhileStatement() {
    constructed = buildToken("while", whileToken)
            and buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void WhileStatement::execute(Env &env) {
    if(!constructed){
        return;
    }
    Env serviceEnv(env);
    conditionalExpression->execute(serviceEnv);
    while(conditionalExpression->getBool()){
        Env localEnv(serviceEnv);
        try {
            blockInstruction->execute(localEnv);
        }
        catch(BreakException &e){
            break;
        }
        catch(ContinueException &e){

        }
        conditionalExpression->execute(serviceEnv);
    }
    //done
}

ObjectType WhileStatement::getObjectType() const {
    return ObjectType::OT_WhileStatement;
}
