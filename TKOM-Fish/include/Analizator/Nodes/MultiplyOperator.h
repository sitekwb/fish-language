//
// Created by Wojtek on 27/05/2020.
//

#ifndef FISH_MULTIPLYOPERATOR_H
#define FISH_MULTIPLYOPERATOR_H

#include <Analizator/Lexer/TokenType.h>

enum class MultiplyOperator {
    MO_MULTIPLY = TokenType::MULTIPLY,
    MO_DIVIDE = TokenType::DIVIDE,
    MO_PERCENT = TokenType::PERCENT,
};


using MultiplyOperatorUP = std::unique_ptr<MultiplyOperator>;


#endif //FISH_MULTIPLYOPERATOR_H
