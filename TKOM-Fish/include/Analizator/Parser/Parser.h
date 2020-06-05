//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_PARSER_H
#define FISH_PARSER_H

#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <Analizator/Lexer/Lexer.h>
#include <Analizator/Nodes/File.h>
#include <Analizator/Nodes/FunctionDefinition.h>
#include <Analizator/Nodes/Term.h>
#include <Analizator/Nodes/WhileStatement.h>
#include <Analizator/Nodes/ForStatement.h>
#include <Analizator/Nodes/Expression.h>
#include <Analizator/Nodes/NewStatement.h>
#include <Analizator/Nodes/ArgumentList.h>
#include <Analizator/Nodes/AssignStatement.h>
#include <Analizator/Nodes/ForiStatement.h>
#include <Analizator/Nodes/ForeachStatement.h>

class Parser {
    Lexer &lexer;

    TokenUP currentToken;
    void nextToken();

    std::string tmpIdName;

    std::pair<std::string&&, std::string&&> buildOptionalTypeNameAndIdentifierName();

    FileUP buildFile();
    FunctionDefinitionUP buildFunctionDefinition();
    ParameterListUP buildParameterList();
    ClassDefinitionUP buildClassDefinition();
    StatementUP buildIfStatement();
    StatementUP buildStatement();
    ParameterUP buildParameter();
    BlockInstructionUP buildBlockInstruction();
    ConditionalExpressionUP buildConditionalExpression();
    AndExpressionUP buildAndExpression();
    TermUP buildTerm();
    OrExpressionUP buildOrExpression();
    RelativeExpressionUP buildRelativeExpression();
    StatementUP buildWhileStatement();
    ClassStatementUP buildClassStatement();
    ClassStatementUP buildMemberDefinition();
    RelativeOperatorUP buildRelativeOperator();
    ArithmeticExpressionUP buildArithmeticExpression();
    AddExpressionUP buildAddExpression();
    MultiplyExpressionUP buildMultiplyExpression();
    MultiplyOperatorUP buildMultiplyOperator();
    AddOperatorUP buildAddOperator();
    ForStatementUP buildForStatement();
    StatementUP buildAssignStatementOrMethodOrFunctionCall();
    StatementUP buildNewStatement();
    StatementUP buildAssignStatement();
    StatementUP buildMethodCallOrPropertyAssign();
    AssignOperatorUP buildAssignOperator();
    ArgumentListUP buildArgumentList();
    ArgumentUP buildArgument();
    StatementUP buildForiStatement();
    StatementUP buildForeachStatement();
    StatementUP buildDeleteStatement();
    StatementUP buildImportStatement();
    StatementUP buildControlStatement();
    StatementUP buildAliasStatement();
    FunctionCallUP buildFunctionCall();
public:
    Parser(Lexer &lexer);
    FileUP parseFile();
};


#endif //FISH_PARSER_H
