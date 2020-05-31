//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/Term.h>


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
    if(!constructed and (buildSymbol<FunctionCall>(functionCall) or buildToken(identifier) or buildToken(CONSTANT, constant))){
        buildRepeatSymbol<ArraySubscript>(arraySubscriptList);

        TokenUPD point;
        IdentifierUPD identifierLocal;
        TokenUPD constantLocal;
        FunctionCallUP functionCallLocal;
        std::list<ArraySubscriptUP> arraySubscriptListLocal;
        while(buildToken(".", point) and (buildSymbol<FunctionCall>(functionCallLocal) or buildToken(identifierLocal) or buildToken(CONSTANT, constantLocal))){
            buildRepeatSymbol<ArraySubscript>(arraySubscriptListLocal);
            repeatList.push_back({move(point), move(functionCallLocal), move(identifierLocal), move(constantLocal), move(arraySubscriptListLocal)});
            arraySubscriptListLocal.clear();
        }
        constructed = true;
    }
}

void Term::execute() {

}

