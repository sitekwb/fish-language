//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include "Analizator/Symbols/ForStatement.h"


ForStatement::ForStatement() {
    constructed = buildToken("for", forToken)
            and buildToken("(", bracketOpen)
            and buildOptionalSymbol<Expression>(expression1Optional)
            and buildToken(";",semicolon1)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(";",semicolon2)
            and buildOptionalSymbol<Expression>(expression2Optional)
            and buildToken(")",bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}


void ForStatement::execute(Env &env) {
    if(!constructed){
        return;
    }

    Env serviceEnv(env);
    if(expression1Optional) {
        expression1Optional->execute(serviceEnv);
    }
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
        expression2Optional->execute(serviceEnv);
        conditionalExpression->execute(serviceEnv);
    }
    //done
}

ObjectType ForStatement::getObjectType() const {
    return ObjectType::OT_ForStatement;
}
