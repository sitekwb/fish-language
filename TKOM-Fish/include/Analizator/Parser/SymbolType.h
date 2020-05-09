//
// Created by Wojtek on 19/04/2020.
//

#ifndef FISH_SYMBOLTYPE_H
#define FISH_SYMBOLTYPE_H

#include <Analizator/Lexer/Token.h>

enum SymbolType {
    Bool,
    Type,
    Library,
    File,
    Statement,
    SimpleStatement,
    ExpressionStatement,
    DeleteStatement,
    ImportStatement,
    NewStatement,
    AssignStatement,
    ControlStatement,
    AliasStatement,
    Expression,
    NewExpression,
    AssignExpression,
    ConditionalExpression,
    AndExpression,
    OrExpression,
    RelativeExpression,
    ArithmeticExpression,
    AddExpression,
    MultiplyExpression,
    Term,
    FunctionCall,
    ArgumentList,
    Argument,
    AssignOperator,
    RelativeOperator,
    AddOperator,
    MultiplyOperator,
    UnarySign,
    UnaryNot,
    ArraySubscript,
    UnsignedIntTerm,
    CompoundStatement,
    BlockInstruction,
    IfStatement,
    WhileStatement,
    ForStatement,
    ForiStatement,
    ForeachStatement,
    FunctionDefinition,
    ClassDefinition,
    ParameterList,
    Parameter,
    Default,
    ClassBody,
    ClassBodyStatement,
    MemberDefinition,
    TOKEN,
    ListIdentifier,
};



#endif //FISH_SYMBOLTYPE_H
