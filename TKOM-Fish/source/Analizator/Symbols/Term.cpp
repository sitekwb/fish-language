//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/Term.h>
#include <Analizator/Interpreter/ObjectType.h>


using namespace std;

Term::Term() : object(*this) {
    constructed = buildToken(INT, intToken)
                  or buildToken(DBL, doubleToken)
                  or buildToken(STR, stringToken)
                  or buildSymbol<Bool>(boolSymbol);
    if (!constructed and buildToken("(", bracketOpen)) {
        constructed = buildSymbol(arithmeticExpression)
                      and buildToken(")", bracketClose);
    }
    if (!constructed and
        (buildSymbol<FunctionCall>(functionCall) or buildToken(identifier) or buildToken(CONSTANT, constant))) {
        buildRepeatSymbol<ArraySubscript>(arraySubscriptList);

        TokenUPD point;
        FunctionCallUP functionCallLocal;
        IdentifierUPD identifierLocal;
        TokenUPD constantLocal;
        std::list<ArraySubscriptUP> arraySubscriptListLocal;
        while (buildToken(".", point) and
               (buildSymbol<FunctionCall>(functionCallLocal) or buildToken(identifierLocal) or
                buildToken(CONSTANT, constantLocal))) {
            buildRepeatSymbol<ArraySubscript>(arraySubscriptListLocal);
            repeatList.push_back({move(point), move(functionCallLocal), move(identifierLocal), move(constantLocal),
                                  move(arraySubscriptListLocal)});
            arraySubscriptListLocal.clear();
        }
        constructed = true;
    }
}

void Term::execute(Env &env) {
    if (!constructed) {
        return;
    }
    if (intToken) {
        object = *intToken;
    } else if (doubleToken) {
        object = *doubleToken;
    } else if (stringToken) {
        object = *stringToken;
    } else if (boolSymbol) {
        boolSymbol->execute(env);
        object = *boolSymbol;
    } else if (arithmeticExpression) {
        arithmeticExpression->execute(env);
        object = arithmeticExpression->getObject();
    } else if (functionCall) {
        functionCall->execute(env);
        object = functionCall->getObject();
    } else if (identifier) {
        object = *identifier;
    } else if (constant) {
        object = *constant;
    }

    if (not arraySubscriptList.empty()) {
        for (auto &arraySubscript: arraySubscriptList) {
            object = object.get()[arraySubscript->getInt()];
        }
    }
    for (auto &e:repeatList) {
        auto &fc = std::get<1>(e);
        auto &id = std::get<2>(e);
        auto &cn = std::get<3>(e);
        if (fc) {
            fc->execute(env);
            object = fc->getObject();
        } else if (id) {
            object = *id;
        } else if (cn) {
            object = *cn;
        }
    }
    // at the end get object from variable name
    if (object.get().getObjectType() == ObjectType::OT_IDENTIFIER or object.get().getObjectType() == ObjectType::OT_CONSTANT) {
        object = env[object.get().getName()];
    }
}

int Term::getInt() {
    return object.get().getInt();
}

double Term::getDouble() {
    return object.get().getDouble();
}

std::string Term::getString() {
    return object.get().getString();
}

bool Term::getBool() {
    return object.get().getBool();
}

Obj &Term::getObject() {
    return object;
}

ObjectType Term::getObjectType() const {
    return ObjectType::OT_Term;
}

Term::Term(double value) : object(*this) {
    doubleToken = TokenUPD(new Token(DBL, to_string(value)), TokenDeleter());
    constructed = true;
}
