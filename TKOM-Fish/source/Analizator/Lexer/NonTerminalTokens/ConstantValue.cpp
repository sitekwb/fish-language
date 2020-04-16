//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/ConstantValue.h"

std::ostream &operator<<(std::ostream &os, const ConstantValue &value) {
    os << "\t\t[CONSTANT_VALUE]";
    return os;
}

void ConstantValue::print(std::ostream &os) const {
    os << *this;
}
