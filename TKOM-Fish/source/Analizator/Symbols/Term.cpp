//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/Symbols/Term.h>


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
    if (!constructed) {
        return;
    }
    if (intToken) {
        termType = TT_INT;
    } else if (doubleToken) {
        termType = TT_DOUBLE;
    } else if (stringToken) {
        termType = TT_STRING;
    } else if (boolSymbol) {
        boolSymbol->execute(env);
        termType = TT_BOOL;
    } else if (arithmeticExpression) {
        arithmeticExpression->execute(env);
        termType = arithmeticExpression->getTermType();
        objects.push_back(arithmeticExpression->getReturnObject());
    } else if (functionCall) {
        functionCall->execute(env);
        termType = functionCall->getReturnType();
        objects.push_back(functionCall->getObject());
    } else if (identifier) {
        termType = TT_IDENTIFIER;
        objects.push_back(*identifier);
    } else if (constant) {
        termType = TT_CONSTANT;
        objects.push_back(*constant);
    }

    if (not objects.empty()) {
        if (not arraySubscriptList.empty()) {
            for (auto &arraySubscript: arraySubscriptList) {
                objects.push_back(objects.front()[arraySubscript->getValue()]);
                objects.pop_front();
            }
        }
        for (auto &e:repeatList) {
            auto &fc = std::get<1>(e);
            auto &id = std::get<2>(e);
            auto &cn = std::get<3>(e);
            if (fc) {
                fc->execute(env);
                termType = fc->getReturnType();
                objects.push_back(fc->getObject());
                objects.pop_front();
            } else if (id) {
                termType = TT_IDENTIFIER;
                objects.push_back(*id);
                objects.pop_front();
            } else if (cn) {
                termType = TT_CONSTANT;
                objects.push_back(*cn);
                objects.pop_front();
            }
        }
    }
    // at the end on access list we have one or more references to objects
}

int Term::getInt() {
    if (termType == TT_INT and intToken) {
        return stoi(intToken->getValue());
    } else throw runtime_error("Getting int from not-int term");
}

double Term::getDouble() {
    if (termType == TT_DOUBLE and doubleToken) {
        return stod(doubleToken->getValue());
    } else throw runtime_error("Getting double from not-double term");
}

std::string Term::getString() {
    if (termType == TT_STRING and stringToken) {
        return stringToken->getValue();
    } else throw runtime_error("Getting string from not-string term");
}

bool Term::getBool() {
    if (termType == TT_BOOL and boolSymbol) {
        return boolSymbol->getValue();
    } else throw runtime_error("Getting bool from not-bool term");
}
