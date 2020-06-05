//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_OREXPRESSION_H
#define FISH_OREXPRESSION_H


#include "RelativeExpression.h"
#include "RelativeOperator.h"
#include <list>

class RelativeExpression;
using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;

class OrExpression {
protected:
    std::list<bool> unaryNotList;
    std::list<RelativeExpressionUP> relativeExpressionList;
    std::list<RelativeOperatorUP> relativeOperatorList;
public:
    OrExpression(std::list<bool> &&unaryNotList,
            std::list<RelativeExpressionUP> &&relativeExpressionList,
            std::list<RelativeOperatorUP> &&relativeOperatorList);
//    template <typename T>
//    bool getValue(T value, T v2, TokenType tokenType) const{
//        bool ret;
//        switch (tokenType) {
//            case EQ_EQ:
//                ret = value == v2;
//                break;
//            case NOT_EQ:
//                ret = value != v2;
//                break;
//            case LESS:
//                ret = value < v2;
//                break;
//            case MORE:
//                ret = value > v2;
//                break;
//            case LESS_EQ:
//                ret = value <= v2;
//                break;
//            case MORE_EQ:
//            default:
//                ret = value >= v2;
//                break;
//        }
//        return ret;
//    }
};
using OrExpressionUP = std::unique_ptr<OrExpression>;


#endif //FISH_OREXPRESSION_H
