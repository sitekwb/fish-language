//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/BreakException.h>
#include <Analizator/Interpreter/ContinueException.h>
#include "Analizator/Symbols/ForiStatement.h"

ForiStatement::ForiStatement() {
    constructed = buildToken("fori", foriToken)
            and buildToken("(", bracketOpen)
            and buildSymbol<UnsignedIntTerm>(unsignedIntTerm)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
}

void ForiStatement::execute(Env &env) {
    if(!constructed){
        return;
    }

    unsignedIntTerm->execute(env);
    for(int i=0; i<unsignedIntTerm->getValue();i++){
        Env localEnv = Env(env);
        Token token(INT, std::to_string(i));
        localEnv.setSymbol("i", token);
        try {
            blockInstruction->execute(localEnv);
        }
        catch(BreakException &e){
            break;
        }
        catch(ContinueException &e){

        }
    }
}
