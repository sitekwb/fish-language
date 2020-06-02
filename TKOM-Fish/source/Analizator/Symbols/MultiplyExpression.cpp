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
    objectList.clear();
    if (!constructed) {
        return;
    }
    if(unarySignOptional) {
        unarySignOptional->execute(env);
        objectList.push_back(*unarySignOptional);
    }
    term->execute(env);
    objectList.push_back(*term);
    evaluateList();
}


double MultiplyExpression::getDouble() const {
    return ((static_cast<Token &>(unarySignOptional->evaluateObject()) == PLUS) ? 1.0 : -1.0) * term->getDouble();
}

int MultiplyExpression::getInt() const {
    return ((static_cast<Token &>(unarySignOptional->evaluateObject()) == PLUS) ? 1 : -1) * term->getInt();
}

ObjectType MultiplyExpression::getObjectType() const {
    return ObjectType::OT_MultiplyExpression;
}

std::string MultiplyExpression::getString() const {
    return term->getObject().getString();
}

bool MultiplyExpression::getBool() const{
    if(unarySignOptional and not unarySignOptional->getObject().getBool()){
        return not term->getBool();
    }
    return term->getObject().getBool();
}




