//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/RelativeExpression.h>

RelativeExpression::RelativeExpression() : object(*this){
    constructed = buildToken("(", bracketOpen)
            and buildSymbol<ConditionalExpression>(conditionalExpression)
            and buildToken(")", bracketClose);
    if(!constructed) {
        constructed = buildSymbol<ArithmeticExpression>(arithmeticExpression);
    }
}

void RelativeExpression::execute(Env &env) {
    if(!constructed){
        return;
    }
    if(conditionalExpression){
        conditionalExpression->execute(env);
        object = *conditionalExpression;
    }
    else if(arithmeticExpression){
        arithmeticExpression->execute(env);
        object = *arithmeticExpression;
    }
    //done
}

Obj &RelativeExpression::getObject() {
    return object;
}

double RelativeExpression::getDouble() const {
    return object.get().getDouble();
}

int RelativeExpression::getInt() const {
    return object.get().getInt();
}

std::string RelativeExpression::getString() const {
    return object.get().getString();
}

bool RelativeExpression::getBool() const {
    return object.get().getBool();
}

ObjectType RelativeExpression::getObjectType() const {
    return ObjectType::OT_RelativeExpression;
}

