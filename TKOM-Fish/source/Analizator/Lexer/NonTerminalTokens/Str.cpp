//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/Str.h"

Str::Str(std::string val) : value(std::move(val)){

}

std::ostream &operator<<(std::ostream &os, const Str &str) {
    os << str.value << "\t\t[STR]";
    return os;
}

void Str::print(std::ostream &os) const {
    os << *this;
}
