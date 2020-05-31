//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/AndExpression.h"

using namespace std;

AndExpression::AndExpression() {
    constructed = buildSymbol<OrExpression>(orExpression);
    while(buildRepeat());
}

bool AndExpression::buildRepeat() {
    TokenUPD andToken;
    OrExpressionUP orExpressionTmp;
    bool constructed = buildToken("and", andToken)
            and buildSymbol<OrExpression>(orExpressionTmp);
    if(constructed){
        repeatList.push_back({move(andToken), move(orExpressionTmp)});
    }
    return constructed;
}

void AndExpression::execute(Env& env) {
    if(!constructed){
        return;
    }
    orExpression->execute(env);
    bool val1 = orExpression->getValue();
    for(auto &pair: repeatList){
        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute(env);
        bool val2 = expr->getValue();
        val1 = val1 and val2;
    }
    value = val1;
}

bool AndExpression::getValue() {
    return value;
}
