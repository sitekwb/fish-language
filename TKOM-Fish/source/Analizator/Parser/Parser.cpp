//
// Created by Wojtek on 16/04/2020.
//

#include <Analizator/Parser/Parser.h>
#include <iostream>
#include <Analizator/Parser/ParsingError.h>
#include <Analizator/Nodes/IfStatement.h>
#include <Analizator/Nodes/Term.h>
#include <Analizator/Nodes/MemberDefinition.h>
#include <Analizator/Nodes/AssignOperator.h>
#include <Analizator/Nodes/AssignStatement.h>
#include <optional>
#include <Analizator/Nodes/DeleteStatement.h>
#include <Analizator/Nodes/ImportStatement.h>
#include <Analizator/Nodes/ControlStatement.h>
#include <Analizator/Nodes/AliasStatement.h>
#include <Analizator/Nodes/PropertyAssignment.h>
#include <Analizator/Nodes/MethodCall.h>


using namespace std;

Parser::Parser(Lexer &lexer) : lexer(lexer) {
    nextToken();
}

void Parser::nextToken() {
    currentToken = lexer.getNextToken();
}

FileUP Parser::parseFile() {
    if (auto file = buildFile()) {
        return move(file);
    }
    throw ParsingError(*currentToken, "[FILE]", typeid(File).name());
}

FileUP Parser::buildFile() {
    list<FunctionDefinitionUP> funcDefList;
    list<ClassDefinitionUP> classDefList;
    list<StatementUP> statementList;
    bool success = true;

    while (success) {
        if (auto funcDef = buildFunctionDefinition()) {
            funcDefList.push_back(move(funcDef));
        } else if (auto classDef = buildClassDefinition()) {
            classDefList.push_back(move(classDef));
        } else if (auto statement = buildStatement()) {
            statementList.push_back(move(statement));
        } else success = false;

        if (*currentToken == SEMICOLON) {
            nextToken();
        }
    }
    return make_unique<File>(move(funcDefList), move(classDefList), move(statementList));
}


FunctionDefinitionUP Parser::buildFunctionDefinition() {
    const string NODE_NAME = typeid(FunctionDefinition).name();

    if (*currentToken != "def") {
        return nullptr;
    }
    nextToken();

    string typeName, idName;
    tie(typeName, idName) = buildOptionalTypeNameAndIdentifierName();
    if (idName.empty()) {
        throw ParsingError(*currentToken, "type name or identifier name", typeid(FunctionDefinition).name());
    }

    if (*currentToken != BRACKET_OPEN) {
        throw ParsingError(*currentToken, "(", NODE_NAME);
    }
    nextToken();

    ParameterListUP parameterList;
    if (not(parameterList = buildParameterList())) {
        throw ParsingError(*currentToken, "Parameter list", NODE_NAME);
    }

    if (*currentToken != BRACKET_CLOSE) {
        throw ParsingError(*currentToken, ")", NODE_NAME);
    }
    nextToken();

    BlockInstructionUP blockInstruction;
    if (not(blockInstruction = buildBlockInstruction())) {
        throw ParsingError(*currentToken, "Statement or {", NODE_NAME);
    }
    return make_unique<FunctionDefinition>(move(typeName), move(idName), move(parameterList), move(blockInstruction));
}


ParameterListUP Parser::buildParameterList() {
    std::list<ParameterUP> parameterList;

    if (auto parameter = buildParameter()) {
        parameterList.push_back(move(parameter));
    } else return nullptr;

    while (*currentToken == COMMA) {
        if (auto parameter = buildParameter()) {
            parameterList.push_back(move(parameter));
        } else throw ParsingError(*currentToken, "PARAMETER", typeid(ParameterList).name());
    }

    return make_unique<ParameterList>(move(parameterList));
}

ParameterUP Parser::buildParameter() {
    string typeName, idName;
    tie(typeName, idName) = buildOptionalTypeNameAndIdentifierName();
    if (idName.empty()) {
        return nullptr;
    }
    // ['=', Default]
    TermUP defaultTerm;
    if (*currentToken == EQUAL) {
        nextToken();

        if (not(defaultTerm = buildTerm())) {
            throw ParsingError(*currentToken, "[TERM]", typeid(Parameter).name());
        }
    }
    return make_unique<Parameter>(move(typeName), move(idName), move(defaultTerm));
}

TermUP Parser::buildTerm() {
    if (*currentToken == INT) {
        int v = get<int>(currentToken->getValue());
        nextToken();
        return make_unique<Term>(v);
    }
    if (*currentToken == DBL) {
        auto v = get<double>(currentToken->getValue());
        nextToken();
        return make_unique<Term>(v);
    }
    if (*currentToken == STR) {
        auto v = get<string>(currentToken->getValue());
        nextToken();
        return make_unique<Term>(v);
    }
    if (*currentToken == BOOL) {
        auto v = get<bool>(currentToken->getValue());
        nextToken();
        return make_unique<Term>(v);
    }
    if (*currentToken == "true") {
        nextToken();
        return make_unique<Term>(true);
    }
    if (*currentToken == "false") {
        nextToken();
        return make_unique<Term>(false);
    }

    ArithmeticExpressionUP arithmeticExpression;
    if (*currentToken == BRACKET_OPEN) {
        nextToken();
        if (not(arithmeticExpression = buildArithmeticExpression())) {
            throw ParsingError(*currentToken, "ArithmeticExpression", "Term");
        }

        if (*currentToken != BRACKET_CLOSE) {
            throw ParsingError(*currentToken, ")", "Term");
        }
        nextToken();

        return make_unique<Term>(arithmeticExpression);
    }

    //TODO method
    list<string> idNameList;
    if (*currentToken != IDENTIFIER) {
        return nullptr;
    }

    string idName = get<string>(currentToken->getValue());
    nextToken();
    idNameList.push_back(move(idName));

    while (*currentToken == POINT) {
        nextToken();

        if (*currentToken == IDENTIFIER) {
            string str = get<string>(currentToken->getValue());
            idNameList.push_back(move(str));
            nextToken();
        } else throw ParsingError(*currentToken, "id", "MethodCallOrPropertyAssign");
    }

    FunctionCallUP functionCall;
    if ((functionCall = buildFunctionCall())) {
        auto methodCall = make_unique<MethodCall>(move(idNameList), move(functionCall));
        return make_unique<Term>(methodCall);
    }
    auto property = make_unique<Property>(move(idNameList));
    return make_unique<Term>(property);
}

StatementUP Parser::buildStatement() {
    StatementUP statement;
    if ((statement = buildIfStatement())
        or (statement = buildWhileStatement())
        or (statement = buildForStatement())
        or (statement = buildForiStatement())
        or (statement = buildForeachStatement())
        or (statement = buildDeleteStatement())
        or (statement = buildImportStatement())
        or (statement = buildControlStatement())
        or (statement = buildAliasStatement())
        or (statement = buildNewStatement())
        or (statement = buildAssignStatementOrMethodOrFunctionCall())) {
        return move(statement);
    }
    return nullptr;
}


StatementUP Parser::buildForiStatement() {
    if (*currentToken != "fori") {
        return nullptr;
    }
    nextToken();

    if (*currentToken != BRACKET_OPEN) {
        throw ParsingError(*currentToken, "(", "ForiStatement");
    }
    nextToken();

    ArithmeticExpressionUP arithmeticExpression;
    if (not(arithmeticExpression = buildArithmeticExpression())) {
        throw ParsingError(*currentToken, "ArithmeticExpression", "Fori");
    }

    if (*currentToken != BRACKET_CLOSE) {
        throw ParsingError(*currentToken, ")", "Fori");
    }
    nextToken();

    BlockInstructionUP blockInstruction;
    if (not(blockInstruction = buildBlockInstruction())) {
        throw ParsingError(*currentToken, "BlockInstruction", "ForStatement");
    }

    return make_unique<Statement>(ForiStatement(move(arithmeticExpression), move(blockInstruction)));
}

StatementUP Parser::buildIfStatement() {
    const std::string NODE_NAME = "IfStatement";

    if (*currentToken != "if") {
        return nullptr;
    }
    nextToken();

    if (*currentToken != BRACKET_OPEN) {
        throw ParsingError(*currentToken, "(", NODE_NAME);
    }
    nextToken();

    ConditionalExpressionUP conditionalExpression;
    if (not(conditionalExpression = buildConditionalExpression())) {
        throw ParsingError(*currentToken, "[CONDITIONAL_EXPRESSION]", NODE_NAME);
    }

    if (*currentToken != BRACKET_CLOSE) {
        throw ParsingError(*currentToken, ")", NODE_NAME);
    }
    nextToken();

    BlockInstructionUP blockInstruction, elseBlockInstruction;
    if (not(blockInstruction = buildBlockInstruction())) {
        throw ParsingError(*currentToken, "[BLOCK_INSTRUCTION]", NODE_NAME);
    }

    if (*currentToken == "else") {
        nextToken();

        if (not(elseBlockInstruction = buildBlockInstruction())) {
            throw ParsingError(*currentToken, "[ELSE_BLOCK_INSTRUCTION]", NODE_NAME);
        }
    }
    return make_unique<Statement>(IfStatement(move(conditionalExpression),
                                              move(blockInstruction),
                                              (elseBlockInstruction)
                                              ? move(elseBlockInstruction) : nullptr));
}

BlockInstructionUP Parser::buildBlockInstruction() {
    list<StatementUP> statementList;
    StatementUP statement;
    if (*currentToken != BLOCK_OPEN) {
        // Statement
        if ((statement = buildStatement())) {
            statementList.push_back(move(statement));
            return make_unique<BlockInstruction>(move(statementList));
        } else return nullptr;
    }
    // *currentToken == BLOCK_OPEN
    nextToken();

    while ((statement = buildStatement())) {
        statementList.push_back(move(statement));
    }

    if (*currentToken != BLOCK_CLOSE) {
        throw ParsingError(*currentToken, "}", typeid(BlockInstruction).name());
    }
    nextToken();

    return make_unique<BlockInstruction>(move(statementList));
}

ClassDefinitionUP Parser::buildClassDefinition() {
    const string NODE_NAME = typeid(ClassDefinition).name();

    if (*currentToken != "class") {
        return nullptr;
    }
    nextToken();

    if (*currentToken != IDENTIFIER) {
        throw ParsingError(*currentToken, "Type name", NODE_NAME);
    }
    string typeName = get<string>(currentToken->getValue());
    nextToken();

    if (*currentToken != BLOCK_OPEN) {
        throw ParsingError(*currentToken, "{", NODE_NAME);
    }
    nextToken();

    list<ClassStatementUP> classStatementList;
    while (auto classStatement = buildClassStatement()) {
        classStatementList.push_back(move(classStatement));
    }

    if (*currentToken != BLOCK_CLOSE) {
        throw ParsingError(*currentToken, "}", NODE_NAME);
    }
    nextToken();

    return make_unique<ClassDefinition>(move(typeName), move(classStatementList));
}

ConditionalExpressionUP Parser::buildConditionalExpression() {
    std::list<AndExpressionUP> andExpressionList;
    if (auto andExpression = buildAndExpression()) {
        andExpressionList.push_back(move(andExpression));
    } else return nullptr;

    while (*currentToken == "or") {
        nextToken();

        if (auto andExpression = buildAndExpression()) {
            andExpressionList.push_back(move(andExpression));
        } else throw ParsingError(*currentToken, "AndExpression", typeid(ConditionalExpression).name());
    }
    return make_unique<ConditionalExpression>(move(andExpressionList));
}

AndExpressionUP Parser::buildAndExpression() {
    std::list<OrExpressionUP> orExpressionList;
    if (auto orExpression = buildOrExpression()) {
        orExpressionList.push_back(move(orExpression));
    } else return nullptr;

    while (*currentToken == "and") {
        nextToken();

        if (auto orExpression = buildOrExpression()) {
            orExpressionList.push_back(move(orExpression));
        } else throw ParsingError(*currentToken, "OrExpression", typeid(AndExpression).name());
    }
    return make_unique<AndExpression>(move(orExpressionList));
}

OrExpressionUP Parser::buildOrExpression() {
    std::list<bool> unaryNotList;
    std::list<RelativeExpressionUP> relativeExpressionList;
    std::list<RelativeOperatorUP> relativeOperatorList;

    bool unaryNotBool = *currentToken == NOT or *currentToken == "not";
    unaryNotList.push_back(unaryNotBool);
    if (unaryNotBool) {
        nextToken();
    }

    if (auto relativeExpression = buildRelativeExpression()) {
        relativeExpressionList.push_back(move(relativeExpression));

    } else if (unaryNotBool) throw ParsingError(*currentToken, "RelativeExpression", "OrExpression");
    else return nullptr;


    while (auto relativeOperator = buildRelativeOperator()) {
        relativeOperatorList.push_back(move(relativeOperator));
        //TODO to submethod
        unaryNotBool = *currentToken == NOT or *currentToken == "not";
        unaryNotList.push_back(unaryNotBool);
        if (unaryNotBool) {
            nextToken();
        }

        if (auto relativeExpression = buildRelativeExpression()) {
            relativeExpressionList.push_back(move(relativeExpression));
        } else throw ParsingError(*currentToken, "RelativeExpression", "OrExpression");
    }

    return make_unique<OrExpression>(move(unaryNotList), move(relativeExpressionList), move(relativeOperatorList));


}

StatementUP Parser::buildWhileStatement() {
    if (*currentToken != "while") {
        return nullptr;
    }
    nextToken();

    if (*currentToken != BRACKET_OPEN) {
        throw ParsingError(*currentToken, "(", "While");
    }
    nextToken();

    ConditionalExpressionUP conditionalExpression;
    if (not(conditionalExpression = buildConditionalExpression())) {
        throw ParsingError(*currentToken, "ConditionalExpression", "While");
    }

    BlockInstructionUP blockInstruction;
    if (not(blockInstruction = buildBlockInstruction())) {
        throw ParsingError(*currentToken, "BlockInstruction", "While");
    }

    return make_unique<Statement>(WhileStatement(move(conditionalExpression), move(blockInstruction)));
}

ClassStatementUP Parser::buildMemberDefinition() {
    const string NODE_NAME = typeid(ClassStatement).name();
    MBP mbp = MBP::MB_PUBLIC;
    bool startedParsing = true;
    if (*currentToken == "public") {
        mbp = MBP::MB_PUBLIC;
        nextToken();
    } else if (*currentToken == "private") {
        mbp = MBP::MB_PRIVATE;
        nextToken();
    } else if (*currentToken == "secret") {
        mbp = MBP::MB_SECRET;
        nextToken();
    } else {
        startedParsing = false;
    }

    bool mutBool = false, staticBool = false;
    if (*currentToken == "mut") {
        mutBool = true;
        nextToken();
        startedParsing = true;
    }
    if (*currentToken == "static") {
        staticBool = true;
        nextToken();
        startedParsing = true;
    }
    string typeName, idName;
    tie(typeName, idName) = buildOptionalTypeNameAndIdentifierName();
    if (idName.empty()) {
        if (startedParsing) {
            throw ParsingError(*currentToken, "optional type or class id", NODE_NAME);
        }
        return nullptr;
    }
    if (*currentToken == SEMICOLON) {
        nextToken();
    }
    return make_unique<ClassStatement>(MemberDefinition(mbp, mutBool, staticBool, move(typeName), move(idName)));
}

ClassStatementUP Parser::buildClassStatement() {
    ClassStatementUP classStatement;
    if ((classStatement = buildMemberDefinition())) {
        return move(classStatement);
    }
    if ((classStatement = buildFunctionDefinition())) {
        return move(classStatement);
    }
    return nullptr;
}

RelativeOperatorUP Parser::buildRelativeOperator() {
    auto type = currentToken->getType();
    if (type == EQ_EQ
        or type == NOT_EQ
        or type == LESS
        or type == MORE
        or type == LESS_EQ
        or type == MORE_EQ) {

        nextToken();
        return make_unique<RelativeOperator>(static_cast<RelativeOperator>(type));
    }
    return nullptr;
}

RelativeExpressionUP Parser::buildRelativeExpression() {
    ConditionalExpressionUP conditionalExpression;
    ArithmeticExpressionUP arithmeticExpression;
    if ((arithmeticExpression = buildArithmeticExpression())) {
        return make_unique<RelativeExpression>(move(arithmeticExpression));
    } else if (*currentToken == BRACKET_OPEN) {
        nextToken();

        if (not(conditionalExpression = buildConditionalExpression())) {
            throw ParsingError(*currentToken, "ConditionalExpression", "RelativeExpression");
        }
        if (*currentToken != BRACKET_CLOSE) {
            throw ParsingError(*currentToken, ")", "RelativeExpression");
        }
        nextToken();

        return make_unique<RelativeExpression>(move(conditionalExpression));
    }
    return nullptr;
}

ArithmeticExpressionUP Parser::buildArithmeticExpression() {
    list<AddExpressionUP> addExpressionList;
    list<AddOperatorUP> addOperatorList;

    AddExpressionUP addExpression;
    if ((addExpression = buildAddExpression())) {
        addExpressionList.push_back(move(addExpression));
    } else return nullptr;

    while (auto addOperator = buildAddOperator()) {
        addOperatorList.push_back(move(addOperator));
        if (not(addExpression = buildAddExpression())) {
            throw ParsingError(*currentToken, "AddExpression", "ArithmeticExpression");
        }
        addExpressionList.push_back(move(addExpression));
    }
    return make_unique<ArithmeticExpression>(move(addExpressionList), move(addOperatorList));
}

AddExpressionUP Parser::buildAddExpression() {
    list<MultiplyExpressionUP> multiplyExpressionList;
    list<MultiplyOperatorUP> multiplyOperatorList;

    MultiplyExpressionUP multiplyExpression;
    if ((multiplyExpression = buildMultiplyExpression())) {
        multiplyExpressionList.push_back(move(multiplyExpression));
    } else return nullptr;

    while (auto multiplyOperator = buildMultiplyOperator()) {
        multiplyOperatorList.push_back(move(multiplyOperator));
        if (not(multiplyExpression = buildMultiplyExpression())) {
            throw ParsingError(*currentToken, "MultiplyExpression", "AddExpression");
        }
        multiplyExpressionList.push_back(move(multiplyExpression));
    }
    return make_unique<AddExpression>(move(multiplyExpressionList), move(multiplyOperatorList));
}

MultiplyExpressionUP Parser::buildMultiplyExpression() {
    bool started = false, unaryMinus = false;
    if (*currentToken == MINUS) {
        started = true;
        unaryMinus = true;
        nextToken();
    } else if (*currentToken == PLUS) {
        started = true;
        nextToken();
    }
    TermUP term;
    if (not(term = buildTerm())) {
        if (started) {
            throw ParsingError(*currentToken, "Term", "MultiplyExpression");
        }
        return nullptr;
    }
    return make_unique<MultiplyExpression>(unaryMinus, move(term));
}

MultiplyOperatorUP Parser::buildMultiplyOperator() {
    auto type = currentToken->getType();
    if (type == MULTIPLY
        or type == PERCENT
        or type == DIVIDE) {
        nextToken();
        return make_unique<MultiplyOperator>(static_cast<MultiplyOperator>(type));
    }
    return nullptr;
}

AddOperatorUP Parser::buildAddOperator() {
    if (*currentToken == PLUS) {
        nextToken();
        return make_unique<AddOperator>(true);
    } else if (*currentToken == MINUS) {
        nextToken();
        return make_unique<AddOperator>(false);
    }
    return nullptr;
}

ForStatementUP Parser::buildForStatement() {
    if (*currentToken != "for") {
        return nullptr;
    }
    nextToken();

    if (*currentToken != BRACKET_OPEN) {
        throw ParsingError(*currentToken, "(", "ForStatement");
    }
    nextToken();

    StatementUP expression;
    if ((expression = buildNewStatement())
        or (expression = buildAssignStatement())) {
        //optional
    }

    if (*currentToken != SEMICOLON) {
        throw ParsingError(*currentToken, "first ;", "ForStatement");
    }
    nextToken();

    ConditionalExpressionUP conditionalExpression;
    if (not(conditionalExpression = buildConditionalExpression())) {
        throw ParsingError(*currentToken, "ConditionalExpression", "ForStatement");
    }

    if (*currentToken != SEMICOLON) {
        throw ParsingError(*currentToken, "first ;", "ForStatement");
    }
    nextToken();

    StatementUP expression2;
    if ((expression = buildNewStatement())
        or (expression = buildAssignStatement())) {
        //optional
    }

    if (*currentToken != BLOCK_CLOSE) {
        throw ParsingError(*currentToken, ")", "ForStatement");
    }
    nextToken();

    BlockInstructionUP blockInstruction;
    if (not(blockInstruction = buildBlockInstruction())) {
        throw ParsingError(*currentToken, "BlockInstruction", "ForStatement");
    }

    return make_unique<ForStatement>(move(expression), move(conditionalExpression), move(expression2),
                                     move(blockInstruction));
}

StatementUP Parser::buildNewStatement() {
    if (*currentToken != "new") {
        return nullptr;
    }
    nextToken();

    bool mutBool = false;
    if (*currentToken == "mut") {
        mutBool = true;
        nextToken();
    }

    bool staticBool = false;
    if (*currentToken == "static") {
        staticBool = true;
        nextToken();
    }

    string typeName, idName;
    tie(typeName, idName) = buildOptionalTypeNameAndIdentifierName();
    if (idName.empty()) {
        throw ParsingError(*currentToken, "optional type and id", "Expression");
    }

    ArgumentListUP argumentList;
    AssignOperatorUP assignOperator;
    ConditionalExpressionUP conditionalExpression;
    if (*currentToken == BRACKET_OPEN) {
        nextToken();
        if (not(argumentList = buildArgumentList())) {
            throw ParsingError(*currentToken, "ArgumentList", "Expression");
        }
        if (*currentToken != BRACKET_CLOSE) {
            throw ParsingError(*currentToken, ")", "Expression");
        }
        nextToken();
    } else if ((assignOperator = buildAssignOperator())) {
        if (not(conditionalExpression = buildConditionalExpression())) {
            throw ParsingError(*currentToken, "ConditionalExpression", "Expression");
        }
    }

    return make_unique<Statement>(
            NewStatement(mutBool, staticBool, move(typeName),
                         move(idName), move(argumentList),
                         move(assignOperator), move(conditionalExpression)));
}

StatementUP Parser::buildAssignStatement() {
    StatementUP statement;

    AssignOperatorUP assignOperator;
    if (not(assignOperator = buildAssignOperator())) {
        return nullptr;
    }

    ConditionalExpressionUP conditionalExpression;
    if (not(conditionalExpression = buildConditionalExpression())) {
        throw ParsingError(*currentToken, "ConditionalExpression", "AssignStatement");
    }

    return make_unique<Expression>(
            AssignStatement(move(tmpIdName), move(assignOperator), move(conditionalExpression)));
}

AssignOperatorUP Parser::buildAssignOperator() {
    auto type = currentToken->getType();
    if (type == EQUAL
        or type == PLUS_EQ
        or type == MINUS_EQ
        or type == MULTIPLY_EQ
        or type == DIVIDE_EQ
        or type == PERCENT_EQ) {
        return make_unique<AssignOperator>(static_cast<AssignOperator>(type));
    }
    return nullptr;
}

ArgumentListUP Parser::buildArgumentList() {
    list<ArgumentUP> argumentList;
    ArgumentUP argument;
    if (not(argument = buildArgument())) {
        return make_unique<ArgumentList>(move(argumentList));
    }
    argumentList.push_back(move(argument));

    while (*currentToken == COMMA) {
        nextToken();
        if ((argument = buildArgument())) {
            argumentList.push_back(move(argument));
        } else throw ParsingError(*currentToken, "Argument", "ArgumentLis");
    }
    return make_unique<ArgumentList>(move(argumentList));
}

ArgumentUP Parser::buildArgument() {
    if (auto conditionalExpression = buildConditionalExpression()) {
        return make_unique<Argument>(move(conditionalExpression));
    }
    return nullptr;
}

std::pair<std::string &&, std::string &&> Parser::buildOptionalTypeNameAndIdentifierName() {
    string typeName, idName;
    if (*currentToken != IDENTIFIER) {
        return {move(typeName), move(idName)};
    }
    // TYPE
    typeName = get<string>(currentToken->getValue());
    nextToken();
    // ID
    if (*currentToken == IDENTIFIER) {
        idName = get<string>(currentToken->getValue());
    } else {
        // there was only id, no type
        idName = typeName;
        typeName = "";
    }
    return {move(typeName), move(idName)};
}

StatementUP Parser::buildForeachStatement() {
    if (*currentToken != "foreach") {
        return nullptr;
    }
    nextToken();

    if (*currentToken != BRACKET_OPEN) {
        throw ParsingError(*currentToken, "(", "ForeachStatement");
    }
    nextToken();

    string idName;
    if (*currentToken == IDENTIFIER) {
        idName = get<string>(currentToken->getValue());
        nextToken();
    } else throw ParsingError(*currentToken, "id", "Foreach");

    if (*currentToken != "in") {
        throw ParsingError(*currentToken, "in", "ForeachStatement");
    }
    nextToken();

    TermUP term;
    if (not(term = buildTerm())) {
        throw ParsingError(*currentToken, "term", "ForeachStatement");
    }

    if (*currentToken != BRACKET_CLOSE) {
        throw ParsingError(*currentToken, ")", "Foreach");
    }
    nextToken();

    BlockInstructionUP blockInstruction;
    if (not(blockInstruction = buildBlockInstruction())) {
        throw ParsingError(*currentToken, "BlockInstruction", "ForeachStatement");
    }

    return make_unique<Statement>(ForeachStatement(move(idName), move(term), move(blockInstruction)));
}

StatementUP Parser::buildDeleteStatement() {
    if (*currentToken != "delete") {
        return nullptr;
    }
    nextToken();

    if (*currentToken == IDENTIFIER) {
        string idName = get<string>(currentToken->getValue());
        return make_unique<Statement>(DeleteStatement(move(idName)));
    } else throw ParsingError(*currentToken, "id", "DeleteStatement");
}

StatementUP Parser::buildImportStatement() {
    if (*currentToken != "import") {
        return nullptr;
    }
    nextToken();

    string idName, idName2;
    if (*currentToken == IDENTIFIER) {
        idName = get<string>(currentToken->getValue());
        nextToken();
    } else throw ParsingError(*currentToken, "id", "ImportStatement");

    if (*currentToken == "as") {
        nextToken();

        if (*currentToken == IDENTIFIER) {
            idName2 = get<string>(currentToken->getValue());
            nextToken();
        } else throw ParsingError(*currentToken, "id2", "ImportStatement");
    }
    return make_unique<Statement>(ImportStatement(move(idName), move(idName2)));
}

StatementUP Parser::buildControlStatement() {
    if (*currentToken == "break") {
        nextToken();
        return make_unique<Statement>(ControlStatement(false));
    } else if (*currentToken == "continue") {
        nextToken();
        return make_unique<Statement>(ControlStatement(true));
    } else if (*currentToken == "return") {
        nextToken();

        if (*currentToken == SEMICOLON) {
            nextToken();
            return make_unique<Statement>(ControlStatement());
        } else if (auto conditionalExpression = buildConditionalExpression()) {
            return make_unique<Statement>(ControlStatement(move(conditionalExpression)));
        } else throw ParsingError(*currentToken, "conditionalExpression or semicolon", "return statement");
    } else return nullptr;
}

StatementUP Parser::buildAliasStatement() {
    if (*currentToken != "alias") {
        return nullptr;
    }
    nextToken();

    string aliasType, type;
    if (*currentToken == IDENTIFIER) {
        aliasType = get<string>(currentToken->getValue());
        nextToken();
    } else throw ParsingError(*currentToken, "alias type", "Alias Statement");

    if (*currentToken == IDENTIFIER) {
        type = get<string>(currentToken->getValue());
        nextToken();
    } else throw ParsingError(*currentToken, "previous type", "Alias Statement");

    return make_unique<Statement>(AliasStatement(move(aliasType), move(type)));
}

FunctionCallUP Parser::buildFunctionCall() {
    if (*currentToken != BRACKET_OPEN) {
        return nullptr;
    }
    string funcName = move(tmpIdName);
    nextToken();

    ArgumentListUP argumentList;
    if (not(argumentList = buildArgumentList())) {
        throw ParsingError(*currentToken, "argument list", "Function Call");
    }

    if (*currentToken != BRACKET_CLOSE) {
        throw ParsingError(*currentToken, ")", "Function Call");
    }
    nextToken();

    return make_unique<FunctionCall>(move(funcName), move(argumentList));
}

StatementUP Parser::buildAssignStatementOrMethodOrFunctionCall() {
    if (*currentToken != IDENTIFIER) {
        return nullptr;
    }
    tmpIdName = get<string>(currentToken->getValue());
    nextToken();

    StatementUP statement;
    if ((statement = buildAssignStatement())
        or (statement = buildMethodCallOrPropertyAssign())) {
        return move(statement);
    }
    FunctionCallUP functionCall;
    if ((functionCall = buildFunctionCall())) {
        return make_unique<Statement>(static_cast<Statement &>(*functionCall));
    } else
        throw ParsingError(*currentToken, "AssignStatement | MethodCallOrPropertyAssign | FunctionCall",
                           "buildAssignStatementOrMethodOrFunctionCall");
}

StatementUP Parser::buildMethodCallOrPropertyAssign() {
    if (*currentToken == POINT) {
        nextToken();
    } else return nullptr;

    list<string> idNameList;
    idNameList.push_back(move(tmpIdName));
    if (*currentToken == IDENTIFIER) {
        string str = get<string>(currentToken->getValue());
        idNameList.push_back(move(str));
        nextToken();
    } else throw ParsingError(*currentToken, "id", "MethodCallOrPropertyAssign");

    while (*currentToken == POINT) {
        nextToken();

        if (*currentToken == IDENTIFIER) {
            string str = get<string>(currentToken->getValue());
            idNameList.push_back(move(str));
            nextToken();
        } else throw ParsingError(*currentToken, "id", "MethodCallOrPropertyAssign");
    }

    StatementUP assignStatement;
    FunctionCallUP functionCall;
    if ((assignStatement = buildAssignStatement())) {
        return make_unique<Statement>(PropertyAssignment(move(idNameList), move(assignStatement)));
    } else if ((functionCall = buildFunctionCall())) {
        return make_unique<Statement>(MethodCall(move(idNameList), move(functionCall)));
    } else throw ParsingError(*currentToken, "AssignStatement | MethodCall", "MethodCallOrPropertyAssign");
}
