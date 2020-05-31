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
    if(!constructed){
        return;
    }
    unaryNotOptional->execute(env);
    relativeExpression->execute(env);
    bool val1 = relativeExpression->getValue();
    if (unaryNotOptional->isConstructed()) {
        val1 = not val1;
    }
    for (auto &tuple: repeatList) {
        // SECOND VALUE
        auto &relativeOperator = *get<0>(tuple);
        auto &unaryNot = *get<1>(tuple);
        auto &expr = *get<2>(tuple);

        relativeOperator.execute(env);
        auto &op = relativeOperator.getValue();
        unaryNot.execute(env);
        expr.execute(env);

        bool val2 = relativeExpression->getValue();
        if (unaryNot.isConstructed()) {
            val2 = not val2;
        }

        if (op == "==") {
            val1 = val1 == val2;
        } else if (op == "!=") {
            val1 = val1 != val2;
        } else if (op == "<") {
            val1 = val1 < val2;
        } else if (op == ">") {
            val1 = val1 > val2;
        } else if (op == "<=") {
            val1 = val1 <= val2;
        } else if (op == ">=") {
            val1 = val1 >= val2;
        } else {
            throw runtime_error("Or Expression invalid value");
        }
    }
    value = val1;
    //done
}

bool OrExpression::getValue() {
    return value;
}
