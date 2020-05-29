//
// Created by Wojtek on 27/05/2020.
//


#include "Analizator/Interpreter/Units/AddExpression.h"

using namespace std;

AddExpression::AddExpression() {
    constructed = buildSymbol<MultiplyExpression>(multiplyExpression);
    while(buildRepeat());
}

bool AddExpression::buildRepeat() {
    MultiplyOperatorUP multiplyOperatorUP;
    MultiplyExpressionUP multiplyExpressionUP;
    if(buildSymbol<MultiplyOperator>(multiplyOperatorUP) and buildSymbol<MultiplyExpression>(multiplyExpressionUP)){
        repeatList.push_back({move(multiplyOperatorUP), move(multiplyExpressionUP)});
        return true;
    }
    return false;
}

void AddExpression::execute() {
    if(!constructed){
        return;
    }
    multiplyExpression->execute();
    bool isDouble1 = multiplyExpression->isDoubleValue(), isDouble2;
    double double1, double2;
    int int1, int2;
    if(isDouble1) {
       double1 = multiplyExpression->getDouble();
    }
    else{
        int1 = multiplyExpression->getInt();
    }

    for(auto &pair: repeatList){
        // OPERATOR
        pair.first->execute();
        auto op = pair.first->getChar();

        // SECOND VALUE
        auto &expr = pair.second;
        expr->execute();

        isDouble2 = expr->isDoubleValue();
        if(isDouble2){
            double2 = expr->getDouble();
        }
        else{
            int2 = expr->getInt();
        }

        switch(op){
            case '*':
                if(isDouble1){
                    double1 = double1 * ((isDouble2)?double2:int2);
                    //isDouble1 = true;
                }
                else if(isDouble2){
                    double1 = int1 * double2;
                    isDouble1 = true;
                }
                else{
                    int1 = int1 * int2;
                    isDouble1 = false;
                }
                break;
            case '/':
                if(isDouble1){
                    double1 = double1 / ((isDouble2)?double2:int2);
                    isDouble1 = true;
                }
                else if(isDouble2){
                    double1 = int1 / double2;
                    isDouble1 = true;
                }
                else{
                    int1 = int1 / int2;
                    isDouble1 = false;
                }
                break;
            case '%':
                int1 = (int)((isDouble1)?double1:int1) % (int)((isDouble2)?double2:int2);
                isDouble1 = false;
                break;
            default:
                throw runtime_error("Add expression parsing error");
        }
    }

    isDouble = isDouble1;
    if(isDouble1){
        doubleValue = double1;
    }
    else{
        intValue = int1;
    }
    //TODO change into few simplier functions
}

bool AddExpression::isDoubleValue() {
    return isDouble;
}

bool AddExpression::getDouble() {
    return doubleValue;
}

bool AddExpression::getInt() {
    return intValue;
}


