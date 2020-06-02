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
    objectList.clear();
    if (!constructed) {
        return;
    }
    multiplyExpression->execute(env);
    objectList.push_back(*multiplyExpression);
    for (auto &pair: repeatList) {
        // OPERATOR
        auto &op = pair.first;
        op->execute(env);
        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute(env);

        objectList.push_back(*op);
        objectList.push_back(*expr);
        evaluateList();
        if(static_cast<Token &>((++objectList.begin())->get()) != PERCENT){
            tokenObject = make_unique<Token>(DBL, to_string(getDoubleValue()));
        }
        else{
            tokenObject = make_unique<Token>(INT, to_string(getIntValue()));
        }
        objectList.clear();
        objectList.push_back(*tokenObject);
    }
    evaluateList();
}

ObjectType AddExpression::getObjectType() const {
    return ObjectType::OT_AddExpression;
}


double AddExpression::getDoubleValue() const {
    auto it = objectList.begin();
    double value = (it++)->get().getDouble();
    while (it != objectList.end()) {
        Token &op = static_cast<Token &>((it++)->get());
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

int AddExpression::getIntValue() const {
    auto it = objectList.begin();
    int value = (it++)->get().getInt();
    while (it != objectList.end()) {
        Token &op = static_cast<Token &>((it++)->get());
        int v2 = (it++)->get().getInt();
        if (op == MULTIPLY) {
            value = value * v2;
        } else if (op == DIVIDE and v2 != 0) { // TODO maybe floating point exception
            value = value / v2;
        } else if (op == PERCENT) {
            value = value % v2;
        }
    }
    return value;
}

std::string AddExpression::getString() const {
    // there aren't */% operators in strings
    // TODO maybe if list.size() > 1 => cout warning
    return objectList.front().get().getString();
}

bool AddExpression::getBool() const {
    return objectList.front().get().getBool();
}





