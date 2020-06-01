//
// Created by Wojtek on 27/05/2020.
//


#include "Analizator/Symbols/AddExpression.h"

using namespace std;

AddExpression::AddExpression() {
    constructed = buildSymbol<MultiplyExpression>(multiplyExpression);
    while (buildRepeat());
}

bool AddExpression::buildRepeat() {
    MultiplyOperatorUP multiplyOperatorUP;
    MultiplyExpressionUP multiplyExpressionUP;
    if (buildSymbol<MultiplyOperator>(multiplyOperatorUP) and buildSymbol<MultiplyExpression>(multiplyExpressionUP)) {
        repeatList.push_back({move(multiplyOperatorUP), move(multiplyExpressionUP)});
        return true;
    }
    return false;
}

void AddExpression::execute(Env &env) {
    if (!constructed) {
        return;
    }
    multiplyExpression->execute(env);
    list.push_back(*multiplyExpression);
    for (auto &pair: repeatList) {
        // OPERATOR
        auto &op = pair.first;
        op->execute(env);
        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute(env);

        list.push_back(*op);
        list.push_back(*expr);
    }
}

ObjectType AddExpression::getObjectType() const {
    return ObjectType::OT_AddExpression;
}


double AddExpression::getDouble() const {
    auto it = list.begin();
    double value = (it++)->get().getDouble();
    while (it != list.end()) {
        int op = (it++)->get().getInt();
        double v2 = (it++)->get().getDouble();
        if (op == MULTIPLY) {
            value = value * v2;
        } else if (op == DIVIDE and v2 != 0) { // TODO maybe floating point exception
            value = value / v2;
        } else if (op == PERCENT) {
            // TODO maybe warning "no % for doubles"
        }
    }
    return value;
}

int AddExpression::getInt() const {
    auto it = list.begin();
    int value = (it++)->get().getInt();
    while (it != list.end()) {
        int op = (it++)->get().getInt();
        int v2 = (it++)->get().getInt();
        if (op == -1) {
            value = value * v2;
        } else if (op == 0 and v2 != 0) { // TODO maybe floating point exception
            value = value / v2;
        } else if (op == 1) {
            value = value % v2;
        }
    }
    return value;
}

std::string AddExpression::getString() const {
    // there aren't */% operators in strings
    // TODO maybe if list.size() > 1 => cout warning
    return list.front().get().getString();
}

bool AddExpression::getBool() const {
    auto it = list.cbegin();
    bool value = (it++)->get().getBool();
    while (it != list.end()) {
        int op = (it++)->get().getInt();
        bool v2 = (it++)->get().getBool();
        if (op == -1) {
            value = value and v2;
        } else if (op == 0) {
            value = value or v2;
        } else if (op == 1) {
            value = value xor v2;
        }
    }
    return value;
}

Obj &AddExpression::getObject() {
    return list.front().get().getObject();
}




