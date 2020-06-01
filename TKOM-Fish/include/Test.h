//
// Created by Wojtek on 29/05/2020.
//

#ifndef FISH_TEST_H
#define FISH_TEST_H

#include <Analizator/Symbols/FunctionCall.h>
#include <Analizator/Symbols/Type.h>
#include <Analizator/Symbols/Expression.h>
#include <Analizator/Symbols/ArgumentList.h>
#include <Analizator/Symbols/AddOperator.h>


class Test {
    void checkFunctionCall(FunctionCall &functionCall);
public:
    void runControlStatementTest();
    void runAddExpressionTest();
    void runAliasStatementTest();
    void run();
    void runExample1();
};

#endif //FISH_TEST_H
