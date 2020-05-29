//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/Units/FunctionCall.h>
#include <Analizator/Interpreter/Units/ArraySubscript.h>
#include "Analizator/Interpreter/Units/Term.h"

using namespace std;

Term::Term() {
    constructed = buildToken(INT, intToken)
                  or buildToken(DBL, doubleToken)
                  or buildToken(STR, stringToken)
                  or buildSymbol<Bool>(boolSymbol);
    if(!constructed and buildToken("(", bracketOpen)){
        constructed = buildSymbol(arithmeticExpression)
                and buildToken(")", bracketClose);
    }
    if(!constructed and (buildToken(identifier) or buildToken(CONSTANT, constant) or buildSymbol<FunctionCall>(functionCall))){
        buildRepeatSymbol<ArraySubscript>(arraySubscriptList);

        TokenUPD point;
        IdentifierUPD identifierLocal;
        TokenUPD constantLocal;
        FunctionCallUP functionCallLocal;
        std::list<ArraySubscriptUP> arraySubscriptListLocal;
        while(buildToken(".", point) and (buildToken(identifierLocal) or buildToken(CONSTANT, constantLocal) or buildSymbol<FunctionCall>(functionCallLocal))){
            buildRepeatSymbol<ArraySubscript>(arraySubscriptListLocal);
            repeatList.push_back({move(point), move(identifierLocal), move(constantLocal), move(functionCallLocal), move(arraySubscriptListLocal)});
            arraySubscriptListLocal.clear();
        }
        constructed = true;
    }
}

void Term::execute() {

}
