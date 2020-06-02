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
    objectList.clear();
    if (!constructed) {
        return;
    }
    orExpression->execute(env);
    objectList.push_back(*orExpression);
    for (auto &pair: repeatList) {
        auto &expr = pair.second;

        expr->execute(env);
        objectList.push_back(*expr);
    }
    evaluateList();
}

double AndExpression::getDouble() const {
    return objectList.front().get().getDouble();
}

int AndExpression::getInt() const {
    return objectList.front().get().getInt();
}

std::string AndExpression::getString() const {
    return objectList.front().get().getString();
}

bool AndExpression::getBool() const {
    auto it = objectList.begin();
    bool value = (it++)->get().getBool();
    while (it != objectList.end()) {
        bool v2 = (it++)->get().getBool();
        value = value and v2;
    }
    return value;
}

ObjectType AndExpression::getObjectType() const {
    return ObjectType::OT_AndExpression;
}

