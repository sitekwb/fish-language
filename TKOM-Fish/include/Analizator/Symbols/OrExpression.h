//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_OREXPRESSION_H
#define FISH_OREXPRESSION_H


#include <Analizator/Symbol.h>
#include "UnaryNot.h"
#include "RelativeExpression.h"
#include "RelativeOperator.h"

class OrExpression;
using OrExpressionUP = std::unique_ptr<OrExpression>;

class RelativeExpression;
using RelativeExpressionUP = std::unique_ptr<RelativeExpression>;

class OrExpression : public Symbol{
protected:
    UnaryNotUP unaryNotOptional;
    RelativeExpressionUP relativeExpression;
    std::list<std::tuple<RelativeOperatorUP, UnaryNotUP, RelativeExpressionUP>> repeatList;

    bool buildRepeat();
    //INTERPRETER
    TokenUP boolToken;
public:
    OrExpression();
    void execute(Env &env) override;
    bool getBool() const override;
    ObjectType getObjectType() const override;
private:
    template <typename T>
    bool getValue(T value, T v2, TokenType tokenType) const{
        bool ret;
        switch (tokenType) {
            case EQ_EQ:
                ret = value == v2;
                break;
            case NOT_EQ:
                ret = value != v2;
                break;
            case LESS:
                ret = value < v2;
                break;
            case MORE:
                ret = value > v2;
                break;
            case LESS_EQ:
                ret = value <= v2;
                break;
            case MORE_EQ:
            default:
                ret = value >= v2;
                break;
        }
        return ret;
    }
};
using OrExpressionUP = std::unique_ptr<OrExpression>;


#endif //FISH_OREXPRESSION_H
