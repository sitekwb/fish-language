//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_PARSER_H
#define FISH_PARSER_H

#include <unordered_set>
#include <map>
#include <list>
#include "Rule.h"

typedef Rule R;

class Parser {
    [[maybe_unused]] static inline std::map<SymbolType, Rule> rules = {
            {Bool,                  Rule(Or, {
                    Rule("true"),
                    Rule("false")
            })},
            {Type,                  Rule(IDENTIFIER)},
            {Library,               Rule(IDENTIFIER)},
            {File,                  Rule(Or, {
                    Rule(Statement),
                    Rule(FunctionDefinition),
                    Rule(ClassDefinition)
            })
            },
            {Statement,             Rule(Or, {
                    Rule(CompoundStatement),
                    Rule(SimpleStatement)
            })},
            {SimpleStatement,       Rule(Or, {
                    Rule(ExpressionStatement),
                    Rule(DeleteStatement),
                    Rule(ImportStatement),
                    Rule(NewStatement),
                    Rule(AssignStatement),
                    Rule(ControlStatement)
            })},
            {ExpressionStatement,   Rule(Expression)},
            {DeleteStatement,       Rule({
                                                 Rule("delete"),
                                                 Rule(IDENTIFIER)
                                         })},
            {ImportStatement,       Rule({
                                                 Rule("import"),
                                                 Rule(Symbol(Library)),
                                                 Rule(Optional, {
                                                         R("as"),
                                                         R(Library)
                                                 })
                                         })},
            {NewStatement,          Rule(NewExpression)},
            {AssignStatement,       Rule(AssignExpression)},
            {ControlStatement,      Rule(Or, {
                    Rule("break"),
                    Rule("continue")
            })},
            {AliasStatement,        Rule({
                                                 Rule("alias"),
                                                 Rule(Type),
                                                 Rule(Type),
                                         })},
            {Expression,            Rule({
                                                 Rule(Optional, {
                                                         Rule(Or, {Rule(ArithmeticExpression), Rule(NewExpression)}),
                                                         Rule(Repeat, {
                                                                 Rule(','),
                                                                 Rule(Or, {Rule(ArithmeticExpression),
                                                                           Rule(NewExpression)}),
                                                         })
                                                 })
                                         })},
            {NewExpression,         Rule({
                                                 Rule("new"),
                                                 Rule(Optional, {Rule("mut")}),
                                                 Rule(Optional, {Rule("static")}),
                                                 Rule(Optional, {Rule(Type)}),
                                                 Rule(Or, {Rule(IDENTIFIER), Rule(CONSTANT)}),
                                                 Rule(Optional, {
                                                         Rule('('),
                                                         Rule(ArgumentList),
                                                         Rule(')'),
                                                 }),
                                                 Rule(Optional, {
                                                         Rule(AssignOperator),
                                                         Rule(ConditionalExpression)
                                                 })
                                         })
            },
            {AssignExpression,      Rule({
                                                 Rule(IDENTIFIER),
                                                 Rule(AssignOperator),
                                                 Rule(Term)
                                         })},
            {ConditionalExpression, Rule({
                                                 Rule(AndExpression),
                                                 Rule(Repeat, {
                                                         Rule("or"),
                                                         Rule(AndExpression)
                                                 })
                                         })},
            {AndExpression,         Rule({
                                                 Rule(OrExpression),
                                                 Rule(Repeat, {
                                                         Rule("and"),
                                                         Rule(OrExpression)
                                                 })
                                         })},
            {OrExpression,          Rule({
                                                 Rule(Optional, {Rule(UnaryNot)}),
                                                 Rule(RelativeExpression),
                                                 Rule(Repeat, {
                                                         Rule(RelativeOperator),
                                                         Rule(Optional, {Rule(UnaryNot)}),
                                                         Rule(RelativeExpression)
                                                 })
                                         })},
            {RelativeExpression,    Rule(Or, {
                    Rule({
                                 Rule('('),
                                 Rule(ConditionalExpression),
                                 Rule(')'),
                         }),
                    Rule(ArithmeticExpression)
            })},
            {ArithmeticExpression,  Rule({
                                                 Rule(AddExpression),
                                                 Rule(Repeat, {
                                                         Rule(AddOperator),
                                                         Rule(AddExpression)
                                                 })
                                         })},
            {AddExpression,         Rule({
                                                 Rule(MultiplyExpression),
                                                 Rule(Repeat, {
                                                         Rule(MultiplyOperator),
                                                         Rule(MultiplyExpression)
                                                 })
                                         })},
            {MultiplyExpression,    Rule({
                                                 Rule(Optional, Rule(UnarySign)),
                                                 Rule(Term)
                                         })
            },
            {Term,                  Rule(Or, {
                    Rule(INT),
                    Rule(DBL),
                    Rule(STR),
                    Rule(Bool),
                    Rule({
                                 Rule('('),
                                 Rule(ArithmeticExpression),
                                 Rule(')'),
                         }),
                    Rule({
                                 Rule(Or, {
                                         Rule(IDENTIFIER),
                                         R(CONSTANT),
                                         R(FunctionCall)
                                 }),
                                 Rule(Repeat, Rule(ArraySubscript)),
                                 Rule(Repeat, {
                                         Rule('.'),
                                         Rule(Or, {
                                                 Rule(IDENTIFIER),
                                                 R(CONSTANT),
                                                 R(FunctionCall)
                                         }),
                                         Rule(Repeat, R(ArraySubscript))
                                 })
                         })
            })},
            {FunctionCall,          Rule({
                                                 Rule(IDENTIFIER),
                                                 Rule('('),
                                                 Rule(ArgumentList),
                                                 Rule(')')
                                         })},
            {ArgumentList,          Rule(Optional, {
                    Rule(Argument),
                    Rule(Repeat, {
                            Rule(','),
                            R(Argument)
                    })
            })
            },
            {Argument,              Rule(ConditionalExpression)},
            {AssignOperator,        Rule(Or, {
                    R('='),
                    R("+="),
                    R("-="),
                    R("*="),
                    R("/="),
                    R("%="),
            })},
            {RelativeOperator,      Rule(Or, {
                    R("=="),
                    R("!="),
                    R('<'),
                    R('>'),
                    R("<="),
                    R(">="),
            })},
            {AddOperator,           Rule(Or, {
                    R('+'),
                    R('-')
            })},
            {MultiplyOperator,      R(Or, {
                    R('*'),
                    R('/'),
                    R('%')
            })},
            {UnarySign,             R(Or, {
                    R("not"),
                    R('!')
            })},
            {ArraySubscript,        R({

                                      })}
    };


    //    std::unordered_set<Token> alphabet;
    Symbol startSymbol;
public:
    Parser();

    void parse();
};


#endif //FISH_PARSER_H
