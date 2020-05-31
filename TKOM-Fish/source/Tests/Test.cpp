//
// Created by Wojtek on 29/05/2020.
//
#define BOOST_TEST_MODULE Fish Tests
#define BOOST_TEST_MAIN main

#include <boost/test/included/unit_test.hpp>
#include <Analizator/Symbols/AliasStatement.h>
#include <Sources/FileSource.h>
#include <Test.h>
#include <Analizator/Symbols/ControlStatement.h>
#include <Analizator/Symbols/File.h>


using namespace std;

void Test::run() {

}


void Test::runAliasStatementTest() {
    auto source = FileSource(make_unique<stringstream>("alias a b"));
    Symbol::setLexer(make_unique<Lexer>(source));
    AliasStatement x;
    BOOST_CHECK(*(x.aliasKeyword) == Token("alias"));
    BOOST_CHECK(*(x.name->identifier) == Token("a"));
    BOOST_CHECK(*(x.type->identifier) == Token("b"));
}

void Test::runAddExpressionTest() {
    //TODO
//    auto source = FileSource(make_unique<stringstream>(""));
//    Symbol::setLexer(make_unique<Lexer>(source));
//    BOOST_CHECK_NO_THROW(AliasStatement a);
//    AliasStatement x;
//    BOOST_CHECK(*(x.aliasKeyword) == Token("alias"));
//    BOOST_CHECK(*(x.name->identifier) == Token("a"));
//    BOOST_CHECK(*(x.type->identifier) == Token("b"));
}
//
//void Test::runControlStatementTest() {
//    auto source = FileSource(make_unique<istringstream>("break continue blablabla"));
//    Symbol::setLexer(make_unique<Lexer>(source));
//    ControlStatement breakStatement;//, continueStatement, blaStatement;
//    BOOST_CHECK(breakStatement.isConstructed());
//    BOOST_CHECK(breakStatement.controlToken);
//    //BOOST_CHECK(continueStatement.controlToken);
//    //BOOST_CHECK(not blaStatement.controlToken);
//
//    BOOST_CHECK(*(breakStatement.controlToken) == Token("break"));
//    //BOOST_CHECK(*(continueStatement.controlToken) == Token("continue"));
//    //BOOST_CHECK(!blaStatement.isConstructed());
//}

void Test::runExample1() {
    auto source = FileSource(make_unique<ifstream>("../examples/example1"));
    Symbol::setLexer(make_unique<Lexer>(source));
    File file;
    std::cout << to_string(file.tokenList.size());
    BOOST_CHECK(file.tokenList.empty());
    BOOST_CHECK(file.isConstructed());
    auto &list = file.filePartList;
    auto listIt = list.begin();

    auto &printFP = **listIt;
    BOOST_CHECK_NO_THROW(printFP.statement->simpleStatement->expressionStatement->
            expression->arithmeticExpression->addExpression->
            multiplyExpression->term->functionCall);
    auto &functionCall = *printFP.statement->simpleStatement->expressionStatement->
            expression->arithmeticExpression->addExpression->multiplyExpression->term->functionCall;
    checkFunctionCall(functionCall);
}

void Test::checkFunctionCall(FunctionCall &fc) {
    BOOST_CHECK(fc.identifier and fc.bracketOpen and not fc.argumentList and fc.bracketClose);
    BOOST_CHECK(*fc.identifier == IDENTIFIER);
    BOOST_CHECK(*fc.bracketOpen == BRACKET_OPEN);
    BOOST_CHECK(*fc.bracketClose == BRACKET_CLOSE);
}

BOOST_AUTO_TEST_SUITE(symbolSuite)

    BOOST_AUTO_TEST_CASE(aliasStatementTest) {
        Test test;
        test.runAliasStatementTest();
    }

    BOOST_AUTO_TEST_CASE(example1){
        Test test;
        test.runExample1();
    }

BOOST_AUTO_TEST_SUITE_END()