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
    if (!constructed) {
        return;
    }
    andExpression->execute(env);
    objectList.push_back(*andExpression);
    for (auto &pair: repeatList) {
        auto &expr = pair.second;
        expr->execute(env);
        objectList.push_back(*expr);
    }
}

double ConditionalExpression::getDouble() const {
    return objectList.front().get().getDouble();
}

int ConditionalExpression::getInt() const {
    return objectList.front().get().getInt();
}

std::string ConditionalExpression::getString() const {
    return objectList.front().get().getString();
}

bool ConditionalExpression::getBool() const {
    auto it = objectList.begin();
    bool value = (it++)->get().getBool();
    while (it != objectList.end()) {
        bool v2 = (it++)->get().getBool();
        value = value or v2;
    }
    return value;
}

ObjectType ConditionalExpression::getObjectType() const {
    return ObjectType::OT_ConditionalExpression;
}

Obj &ConditionalExpression::getObject() {
    return objectList.front().get();
}

