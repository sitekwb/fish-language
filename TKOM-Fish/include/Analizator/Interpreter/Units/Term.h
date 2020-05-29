//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_TERM_H
#define FISH_TERM_H


#include <Analizator/Interpreter/Symbol.h>
#include "Bool.h"
#include "FunctionCall.h"
#include "ArraySubscript.h"
#include "ArithmeticExpression.h"
#include "RelativeExpression.h"

class ArithmeticExpression;
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;

class FunctionCall;
using FunctionCallUP = std::unique_ptr<FunctionCall>;


class Term : public Symbol{
protected:
    TokenUPD intToken;
    TokenUPD doubleToken;
    TokenUPD stringToken;
    BoolUP boolSymbol;

    TokenUPD bracketOpen;
    ArithmeticExpressionUP arithmeticExpression;
    TokenUPD bracketClose;

    IdentifierUPD identifier;
    TokenUPD constant;
    FunctionCallUP functionCall;
    std::list<ArraySubscriptUP> arraySubscriptList;

    std::list<std::tuple<TokenUPD, TokenUPD, TokenUPD, FunctionCallUP, std::list<ArraySubscriptUP>>> repeatList;
public:
    Term();
    void execute() override;
};

using TermUP = std::unique_ptr<Term>;

#endif //FISH_TERM_H
