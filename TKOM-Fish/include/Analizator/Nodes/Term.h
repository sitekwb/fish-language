//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_TERM_H
#define FISH_TERM_H

#include <Analizator/Lexer/Token.h>
#include "ArithmeticExpression.h"
#include "MethodCall.h"
#include "Property.h"

#include <string>
#include <variant>

class ArithmeticExpression;
using ArithmeticExpressionUP = std::unique_ptr<ArithmeticExpression>;

class MethodCall;
using MethodCallUP = std::unique_ptr<MethodCall>;

class Property;
using PropertyUP = std::unique_ptr<Property>;



using TermVariant = std::variant<std::string,bool,int,double,ArithmeticExpressionUP,MethodCallUP, PropertyUP>;


class Term {
protected:
    TermVariant v;
public:
    Term(bool v);
    Term(int v);
    Term(double v);
    Term(ArithmeticExpressionUP &v);
    Term(MethodCallUP &v);
    Term(PropertyUP &v);
    Term(std::string &v);


};

using TermUP = std::unique_ptr<Term>;

#endif //FISH_TERM_H
