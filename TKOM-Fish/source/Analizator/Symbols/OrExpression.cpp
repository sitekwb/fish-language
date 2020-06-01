//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/OrExpression.h"


using namespace std;

OrExpression::OrExpression() {
    constructed = buildOptionalSymbol<UnaryNot>(unaryNotOptional)
                  and buildSymbol<RelativeExpression>(relativeExpression);
    while (buildRepeat());
}

bool OrExpression::buildRepeat() {
    RelativeOperatorUP relativeOperatorUP;
    UnaryNotUP unaryNotUP;
    RelativeExpressionUP relativeExpressionUP;
    bool constructed = buildSymbol<RelativeOperator>(relativeOperatorUP)
                       and buildOptionalSymbol<UnaryNot>(unaryNotUP)
                       and buildSymbol<RelativeExpression>(relativeExpressionUP);
    if (constructed) {
        repeatList.push_back({move(relativeOperatorUP), move(unaryNotUP), move(relativeExpressionUP)});
    }
    return constructed;
}

void OrExpression::execute(Env &env) {
    if (!constructed) {
        return;
    }
    if(unaryNotOptional) {
        unaryNotOptional->execute(env);
        objectList.push_back(*unaryNotOptional);
    }
    relativeExpression->execute(env);
    objectList.push_back(*relativeExpression);
    for (auto &tuple: repeatList) {
        auto &op = std::get<0>(tuple);
        auto &unaryNot = std::get<1>(tuple);
        auto &expr = std::get<2>(tuple);

        op->execute(env);
        if(unaryNot) {
            unaryNot->execute(env);
        }
        expr->execute(env);

        objectList.push_back(*op);
        objectList.push_back(*unaryNot);
        objectList.push_back(*expr);
    }
}

double OrExpression::getDouble() const {
    return objectList.front().getDouble();
}

int OrExpression::getInt() const {
    return objectList.front().getInt();
}

std::string OrExpression::getString() const {
    return objectList.front().getString();
}

bool OrExpression::getBool() const {
    auto it = objectList.begin();
    bool unaryNot = (it++)->getBool();
    bool value = (it++)->getBool();
    if (unaryNot) {
        value = not value;
    }
    while (it != objectList.end()) {
        int op = (it++)->getInt();
        unaryNot = (it++)->getBool();
        bool v2 = (it++)->getBool();
        switch (op) {
            case EQ_EQ:
                value = value == v2;
                break;
            case NOT_EQ:
                value = value != v2;
                break;
            case LESS:
                value = value < v2;
                break;
            case MORE:
                value = value > v2;
                break;
            case LESS_EQ:
                value = value <= v2;
                break;
            case MORE_EQ:
            default:
                value = value >= v2;
                break;
        }
        if (unaryNot) {
            value = not value;
        }
    }
    return value;
}

ObjectType OrExpression::getObjectType() const {
    return ObjectType::OT_OrExpression;
}

Object &OrExpression::getObject() {
    return objectList.front();
}
