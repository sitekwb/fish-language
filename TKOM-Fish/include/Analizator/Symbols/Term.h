//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_TERM_H
#define FISH_TERM_H


#include <Analizator/Symbol.h>
#include "Bool.h"
#include "FunctionCall.h"
#include "ArraySubscript.h"
#include "ArithmeticExpression.h"
#include "RelativeExpression.h"

class ArithmeticExpression;
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;

class FunctionCall;
using FunctionCallUP = std::unique_ptr<FunctionCall>;

class ArraySubscript;
using ArraySubscriptUP = std::unique_ptr<ArraySubscript>;

class Term : public Symbol{
protected:
    TokenUPD intToken;
    TokenUPD doubleToken;
    TokenUPD stringToken;
    BoolUP boolSymbol;

    TokenUPD bracketOpen;
    ArithmeticExpressionUP arithmeticExpression;
    TokenUPD bracketClose;

    FunctionCallUP functionCall;
    IdentifierUPD identifier;
    TokenUPD constant;
    std::list<ArraySubscriptUP> arraySubscriptList;

    std::list<std::tuple<TokenUPD, FunctionCallUP, TokenUPD, TokenUPD, std::list<ArraySubscriptUP>>> repeatList;
public:
    Term();
    void execute() override;
    friend class Test;
};

using TermUP = std::unique_ptr<Term>;

#endif //FISH_TERM_H