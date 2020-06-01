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
    if (!constructed) {
        return;
    }
    addExpression->execute(env);
    list.push_back(*addExpression);
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

double ArithmeticExpression::getDouble() const{
    auto it = list.begin();
    double value = (it++)->getDouble();
    while (it != list.end()) {
        bool op = (it++)->getBool();
        double v2 = (it++)->getDouble();
        if (op){
            value = value + v2;
        } else {
            value = value - v2;
        }
    }
    return value;
}
int ArithmeticExpression::getInt() const{
    auto it = list.begin();
    int value = (it++)->getInt();
    while (it != list.end()) {
        bool op = (it++)->getBool();
        int v2 = (it++)->getInt();
        if (op){
            value = value + v2;
        } else {
            value = value - v2;
        }
    }
    return value;
}
std::string ArithmeticExpression::getString() const{
    auto it = list.begin();
    std::string value = (it++)->getString();
    while (it != list.end()) {
        bool op = (it++)->getBool();
        std::string v2 = (it++)->getString();
        if (op){
            value = value + v2;
        }
        // TODO maybe warning about - in strings concatenation
    }
    return value;
}
bool ArithmeticExpression::getBool() const{
    auto it = list.begin();
    bool value = (it++)->getBool();
    while (it != list.end()) {
        bool op = (it++)->getBool();
        bool v2 = (it++)->getBool();
        if (op){
            value = value or v2;
        } else {
            value = value and not v2;
        }
    }
    return value;
}
ObjectType ArithmeticExpression::getObjectType() const{
    return ObjectType::OT_ArithmeticExpression;
}
Object &ArithmeticExpression::getObject(){
    return list.front();
}

