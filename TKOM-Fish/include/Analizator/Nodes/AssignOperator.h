//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_ASSIGNOPERATOR_H
#define FISH_ASSIGNOPERATOR_H


#include <Analizator/Lexer/TokenType.h>
#include <memory>

enum class AssignOperator{
    AO_EQUAL = TokenType::EQUAL,
    AO_PLUS_EQ = TokenType::PLUS_EQ,
    AO_MINUS_EQ = TokenType::MINUS_EQ,
    AO_MULTIPLY_EQ = TokenType::MULTIPLY_EQ,
    AO_DIVIDE_EQ = TokenType::DIVIDE_EQ,
    AO_PERCENT_EQ = TokenType::PERCENT_EQ,
};

using AssignOperatorUP = std::unique_ptr<AssignOperator>;

#endif //FISH_ASSIGNOPERATOR_H
