//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/IfStatement.h"

IfStatement::IfStatement() {
    constructed = buildToken("if", ifToken)
            and buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose)
            and buildSymbol<BlockInstruction>(blockInstruction);
    if(constructed and buildToken("else", elseOptional)) {
        constructed = constructed and buildSymbol<BlockInstruction>(elseBlockInstruction);
    }
}

void IfStatement::execute(Env &env) {
    if(!constructed){
        return;
    }
    Env localEnv(env);
    conditionalExpression->execute(localEnv);
    if(conditionalExpression->getBool()){
        blockInstruction->execute(localEnv);
    }
    else if(elseOptional){
        Env elseEnv(env);
        elseBlockInstruction->execute(elseEnv);
    }
}

ObjectType IfStatement::getObjectType() const {
    return ObjectType::OT_IfStatement;
}
