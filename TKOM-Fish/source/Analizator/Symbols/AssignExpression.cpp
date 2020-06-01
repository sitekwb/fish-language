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
    if(!constructed){
        return;
    }
    assignOperator->execute(env);
    conditionalExpression->execute(env);
    auto name = move(identifier->getString());
    auto &obj = env[name];
    double objDouble = obj.getDouble();
    double secondDouble = conditionalExpression->getDouble();
    double newValue;
    switch(assignOperator->getInt()){
        case '+':
            newValue = objDouble+secondDouble;
            break;
        case '-':
            newValue = objDouble - secondDouble;
            break;
        case '*':
            newValue = objDouble * secondDouble;
            break;
        case '/':
            newValue = objDouble / secondDouble;
            break;
        case '%':
            newValue = obj.getInt() % conditionalExpression->getInt();
            break;
        default:
            env.setSymbol(name, conditionalExpression->getObject());
    }

    if(assignOperator->getInt() != '=') {
        newObject = std::make_unique<Term>(newValue);
        env.setSymbol(name, *newObject);
    }
}

ObjectType AssignExpression::getObjectType() const {
    return ObjectType::OT_AssignExpression;
}
