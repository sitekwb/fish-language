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

void ArithmeticExpression::execute() {
    if(!constructed){
        return;
    }
    addExpression->execute();
    bool isDouble1 = addExpression->isDoubleValue(), isDouble2;
    double double1, double2;
    int int1, int2;
    if(isDouble1) {
        double1 = addExpression->getDouble();
    }
    else{
        int1 = addExpression->getInt();
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
            case '+':
                if(isDouble1){
                    double1 = double1 + ((isDouble2)?double2:int2);
                    //isDouble1 = true;
                }
                else if(isDouble2){
                    double1 = int1 + double2;
                    isDouble1 = true;
                }
                else{
                    int1 = int1 + int2;
                    isDouble1 = false;
                }
                break;
            case '-':
                if(isDouble1){
                    double1 = double1 - ((isDouble2)?double2:int2);
                    isDouble1 = true;
                }
                else if(isDouble2){
                    double1 = int1 - double2;
                    isDouble1 = true;
                }
                else{
                    int1 = int1 - int2;
                    isDouble1 = false;
                }
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

