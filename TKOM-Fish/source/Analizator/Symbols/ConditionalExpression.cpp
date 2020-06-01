//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ConditionalExpression.h"

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

void ConditionalExpression::execute(Env &env) {
    andExpression->execute(env);
    bool val1 = andExpression->getValue();
    for(auto &pair: repeatList){
        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute(env);
        bool val2 = expr->getValue();
        val1 = val1 or val2;
    }
    value = val1;
}

double ConditionalExpression::getDouble() const {
    return objectList.front().getDouble();
}

int ConditionalExpression::getInt() const {
    return objectList.front().getInt();
}

std::string ConditionalExpression::getString() const {
    return objectList.front().getString();
}

bool ConditionalExpression::getBool() const {
    auto it = objectList.begin();
    bool value = (it++)->getBool();
    while (it != objectList.end()) {
        bool v2 = (it++)->getBool();
        value = value or v2;
    }
    return value;
}

ObjectType ConditionalExpression::getObjectType() const {
    return ObjectType::OT_ConditionalExpression;
}

Object &ConditionalExpression::getObject() {
    return objectList.front();
}

