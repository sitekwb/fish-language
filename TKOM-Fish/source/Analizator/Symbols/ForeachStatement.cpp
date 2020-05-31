//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/ForeachStatement.h>
#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>

ForeachStatement::ForeachStatement() {
    constructed = buildToken("foreach",foreachToken)
            and buildToken("(", bracketOpen)
            and buildToken(identifier)
            and buildToken("in", inToken)
            and buildSymbol<Term>(term)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void ForeachStatement::execute(Env &env) {
    if(!constructed){
        return;
    }

    term->execute(env);
    Object &listObject = term->getObject();
    for(int i=0; i<listObject.getSize(); i++) {
        Env localEnv = Env(env);
        localEnv.setSymbol(identifier->getValue(), listObject[i]);
        try {
            blockInstruction->execute(localEnv);
        }
        catch(BreakException &e){
            break;
        }
        catch(ContinueException &e){

        }
    }
    //done
}

