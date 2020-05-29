//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ConditionalExpression.h"

using namespace std;

ConditionalExpression::ConditionalExpression() {
    constructed = buildSymbol<AndExpression>(andExpression);
    while(buildRepeat());
}

bool ConditionalExpression::buildRepeat() {
    TokenUPD orToken;
    AndExpressionUP andExpressionTmp;
    bool constructed = buildToken("or", orToken)
                       and buildSymbol<AndExpression>(andExpressionTmp);
    if(constructed){
        repeatList.push_back({move(orToken), move(andExpressionTmp)});
    }
    return constructed;
}

void ConditionalExpression::execute() {
    andExpression->execute();
    bool val1 = andExpression->getValue();
    for(auto &pair: repeatList){
        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute();
        bool val2 = expr->getValue();
        val1 = val1 or val2;
    }
    value = val1;
}

bool ConditionalExpression::getValue() {
    return value;
}
