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

void OrExpression::execute() {
    //TODO in all executes check if it's constructed
    unaryNotOptional->execute();
    relativeExpression->execute();
    bool val1 = relativeExpression->getValue();
    if (unaryNotOptional->isConstructed()) {
        val1 = not val1;
    }
    for (auto &tuple: repeatList) {
        // SECOND VALUE
        auto &operatorObject = *get<0>(tuple);
        auto &unaryNot = *get<1>(tuple);
        auto &expr = *get<2>(tuple);

        operatorObject.execute();
        auto &op = operatorObject.getValue();
        unaryNot.execute();
        expr.execute();

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
}

bool OrExpression::getValue() {
    return value;
}
