//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/AssignExpression.h"

AssignExpression::AssignExpression() {
    constructed = buildToken(identifier)
                  and buildSymbol<AssignOperator>(assignOperator)
                  and buildSymbol<ConditionalExpression>(conditionalExpression);
}

void AssignExpression::execute(Env &env) {
    if (!constructed) {
        return;
    }
    assignOperator->execute(env);
    conditionalExpression->execute(env);
    auto name = move(identifier->getString());
    auto &obj = env[name];
    double objDouble = obj.getDouble();
    double secondDouble = conditionalExpression->getDouble();
    double newValue;
    Token &op = static_cast<Token &>(assignOperator->evaluateObject());
    if (op == PLUS_EQ) {
        newValue = objDouble + secondDouble;
    } else if (op == MINUS_EQ) {
        newValue = objDouble - secondDouble;
    } else if (op == MULTIPLY_EQ) {
        newValue = objDouble * secondDouble;
    } else if (op == DIVIDE_EQ) {
        newValue = objDouble / secondDouble;
    } else if (op == PERCENT_EQ) {
        newValue = obj.getInt() % conditionalExpression->getInt();
    }

    if (op == EQUAL) {
        env.setSymbol(name, conditionalExpression->getObject());
    } else {
        doubleObject = std::make_unique<Token>(DBL, std::to_string(newValue));
        env.setSymbol(name, *doubleObject);
    }
}

ObjectType AssignExpression::getObjectType() const {
    return ObjectType::OT_AssignExpression;
}
