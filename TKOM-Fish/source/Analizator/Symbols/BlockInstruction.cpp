//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/BlockInstruction.h"

BlockInstruction::BlockInstruction() {
    // '{', {Statement}, '}'
    constructed = buildToken("{", blockOpen);
    if(constructed){
        StatementUP statement;
        while(buildSymbol<Statement>(statement)){
            statementList.push_back(move(statement));
        }
        constructed = buildToken("}", blockClose);
    }
    // Statement
    else{
        StatementUP statement;
        constructed = buildSymbol<Statement>(statement);
        if(constructed){
            statementList.push_back(move(statement));
        }
    }
}

void BlockInstruction::execute() {
    // TODO interprete with local scope and environment
}
