//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/ArithmeticExpression.h"


using namespace std;

ArithmeticExpression::ArithmeticExpression() {
    constructed = buildSymbol<AddExpression>(addExpression);
    while(buildRepeat());
}

bool ArithmeticExpression::buildRepeat() {
    AddOperatorUP addOperatorUP;
    AddExpressionUP addExpressionUP;
    if(buildSymbol<AddOperator>(addOperatorUP) and buildSymbol<AddExpression>(addExpressionUP)){
        repeatList.push_back({move(addOperatorUP), move(addExpressionUP)});
        return true;
    }
    return false;
}

void ArithmeticExpression::execute(Env &env) {
    objectList.clear();
    if (!constructed) {
        return;
    }
    addExpression->execute(env);
    objectList.push_back(*addExpression);
    for (auto &pair: repeatList) {
        // OPERATOR
        auto &op = pair.first;
        op->execute(env);
        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute(env);

        objectList.push_back(*op);
        objectList.push_back(*expr);
    }
    evaluateList();
}

double ArithmeticExpression::getDouble() const{
    auto it = objectList.begin();
    double value = (it++)->get().getDouble();
    while (it != objectList.end()) {
        Token &op = static_cast<Token &>((it++)->get());
        double v2 = (it++)->get().getDouble();
        if (op == PLUS){
            value = value + v2;
        } else {
            value = value - v2;
        }
    }
    return value;
}
int ArithmeticExpression::getInt() const{
    auto it = objectList.begin();
    int value = (it++)->get().getInt();
    while (it != objectList.end()) {
        Token &op = static_cast<Token &>((it++)->get());
        int v2 = (it++)->get().getInt();
        if (op == PLUS){
            value = value + v2;
        } else {
            value = value - v2;
        }
    }
    return value;
}
std::string ArithmeticExpression::getString() const{
    auto it = objectList.begin();
    std::string value = (it++)->get().getString();
    while (it != objectList.end()) {
        Token &op = static_cast<Token &>((it++)->get());
        std::string v2 = (it++)->get().getString();
        if (op == PLUS){
            value = value + v2;
        }
        // TODO maybe warning about - in strings concatenation
    }
    return value;
}
bool ArithmeticExpression::getBool() const{
    return objectList.front().get().getBool();
}
ObjectType ArithmeticExpression::getObjectType() const{
    return ObjectType::OT_ArithmeticExpression;
}

