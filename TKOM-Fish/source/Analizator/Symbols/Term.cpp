//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/Term.h>
#include <Analizator/Interpreter/ObjectType.h>


using namespace std;

Term::Term() {
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
    objectList.clear();
    if (!constructed) {
        return;
    }
    if (intToken) {
        objectList.push_back(*intToken);
    } else if (doubleToken) {
        objectList.push_back(*doubleToken);
    } else if (stringToken) {
        objectList.push_back(*stringToken);
    } else if (boolSymbol) {
        boolSymbol->execute(env);
        objectList.push_back(*boolSymbol);
    } else if (arithmeticExpression) {
        arithmeticExpression->execute(env);
        objectList.push_back(arithmeticExpression->getObject());
    } else if (functionCall) {
        functionCall->execute(env);
        objectList.push_back(functionCall->getObject());
    } else if (identifier) {
        objectList.push_back(*identifier);
    } else if (constant) {
        objectList.push_back(*constant);
    }

    if (not arraySubscriptList.empty()) {
        for (auto &arraySubscript: arraySubscriptList) {
            objectList.clear();
            objectList.push_back(evaluateObject()[arraySubscript->getInt()]);
        }
    }
    for (auto &e:repeatList) {
        auto &fc = std::get<1>(e);
        auto &id = std::get<2>(e);
        auto &cn = std::get<3>(e);
        if (fc) {
            fc->execute(env);
            objectList.clear();
            objectList.push_back(fc->getObject());
        } else if (id) {
            objectList.clear();
            objectList.push_back(*id);
        } else if (cn) {
            objectList.clear();
            objectList.push_back(*cn);
        }
    }
    evaluateList();
    // at the end get object from variable name
    auto ot = getObject().getObjectType();
    if (ot == ObjectType::OT_IDENTIFIER or
        ot == ObjectType::OT_CONSTANT) {
        Obj &obj = env[static_cast<Token &>(getObject()).getValue()];
        objectList.clear();
        objectList.push_back(obj);
    }
}

ObjectType Term::getObjectType() const {
    return ObjectType::OT_Term;
}

Term::Term(double value) {
    doubleToken = TokenUPD(new Token(DBL, to_string(value)), TokenDeleter());
    constructed = true;
}

