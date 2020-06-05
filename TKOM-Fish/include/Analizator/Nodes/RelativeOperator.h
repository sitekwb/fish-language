//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_RELATIVEOPERATOR_H
#define FISH_RELATIVEOPERATOR_H

#include <memory>
#include <list>
#include <Analizator/Lexer/TokenType.h>

enum class RelativeOperator{
    RO_EQ_EQ = TokenType::EQ_EQ,
    RO_NOT_EQ = TokenType::NOT_EQ,
    RO_LESS = TokenType::LESS,
    RO_MORE = TokenType::MORE,
    RO_LESS_EQ = TokenType::LESS_EQ,
    RO_MORE_EQ = TokenType::MORE_EQ,
};

using RelativeOperatorUP = std::unique_ptr<RelativeOperator>;

#endif //FISH_RELATIVEOPERATOR_H
