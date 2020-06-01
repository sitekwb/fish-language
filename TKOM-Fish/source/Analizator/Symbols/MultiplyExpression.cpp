//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Interpreter/ObjectType.h>
#include "Analizator/Symbols/MultiplyExpression.h"

MultiplyExpression::MultiplyExpression() {
    buildSymbol<UnarySign>(unarySignOptional);
    constructed = buildSymbol<Term>(term);
}

void MultiplyExpression::execute(Env &env) {
    if (!constructed) {
        return;
    }
    unarySignOptional->execute(env);
    term->execute(env);
}


double MultiplyExpression::getDouble() const {
    return ((unarySignOptional) ? unarySignOptional->getDouble() : 1.0) * term->getDouble();
}

int MultiplyExpression::getInt() const {
    return ((unarySignOptional) ? unarySignOptional->getInt() : 1) * term->getInt();
}

ObjectType MultiplyExpression::getObjectType() const {
    return ObjectType::OT_MultiplyExpression;
}

std::string MultiplyExpression::getString() const {
    return term->getString();
}

bool MultiplyExpression::getBool() const{
    if(unarySignOptional and not unarySignOptional->getBool()){
        return not term->getBool();
    }
    return term->getBool();
}

Object &MultiplyExpression::getObject() {
    return term->getObject();
}



