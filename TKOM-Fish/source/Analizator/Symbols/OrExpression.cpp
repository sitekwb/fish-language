//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Symbols/OrExpression.h"
#include <Analizator/Interpreter/Obj.h>

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
    objectList.clear();
    if (!constructed) {
        return;
    }
    if(unaryNotOptional) {
        unaryNotOptional->execute(env);
        objectList.push_back(*unaryNotOptional);
    }
    relativeExpression->execute(env);
    objectList.push_back(*relativeExpression);
    for (auto &tuple: repeatList) {
        auto &op = std::get<0>(tuple);
        auto &unaryNot = std::get<1>(tuple);
        auto &expr = std::get<2>(tuple);

        op->execute(env);
        if(unaryNot) {
            unaryNot->execute(env);
            objectList.push_back(*unaryNot);
        }
        expr->execute(env);

        objectList.push_back(*op);
        objectList.push_back(*expr);

    }
    evaluateList();
    if(objectList.size() > 1) {
        boolToken = make_unique<Token>((getBool()) ? "true" : "false");
        objectList.clear();
        objectList.push_back(*boolToken);
        evaluateList();
    }
}


bool OrExpression::getBool() const {
    auto it = objectList.begin();
    std::reference_wrapper<Obj> first = (it++)->get();
    auto &notToken = static_cast<Token &>(first.get());
    bool unaryNot = notToken == Token(KEYWORD, "not") or notToken == NOT;
    Obj &valueObject = first;
    bool value;
    bool isBool = false;
    if(unaryNot) {
        valueObject = (it++)->get();
    }
    if (unaryNot) {
        value = not valueObject.getBool();
        isBool = true;
    }
    while (it != objectList.end()) {
        Token &op = static_cast<Token &>((it++)->get());
        first = (it++)->get();
        unaryNot = first.get().getObjectType() == ObjectType::OT_UnaryNot;
        Obj &valueObject2 = first;
        bool v2, isBool2 = false;
        if(unaryNot) {
            valueObject2 = (it++)->get();
        }
        if (unaryNot) {
            v2 = not valueObject.getBool();
            isBool2 = true;
        }
        ObjectType ot1 = valueObject.getObjectType(), ot2=valueObject2.getObjectType();
        if(isBool or isBool2 or ot1 == ObjectType::OT_Bool or ot2 == ObjectType::OT_Bool){
            value = getValue<bool>((isBool)?value:valueObject.getBool(), (isBool2)?v2:valueObject.getBool(), op.getType());
        }
        else if(ot1 == ObjectType::OT_DOUBLE or ot2 == ObjectType::OT_DOUBLE){
            value = getValue<double>(valueObject.getDouble(), valueObject2.getDouble(), op.getType());
        }
        else if(ot1 == ObjectType::OT_INT and ot2 == ObjectType::OT_INT){
            value = getValue<int>(valueObject.getInt(), valueObject2.getInt(), op.getType());
        }
        else if(ot1 == ObjectType::OT_STRING and ot2 == ObjectType::OT_STRING){
            value = getValue<std::string>(valueObject.getString(), valueObject2.getString(), op.getType());
        }
    }
    return value;
}

ObjectType OrExpression::getObjectType() const {
    return ObjectType::OT_OrExpression;
}
