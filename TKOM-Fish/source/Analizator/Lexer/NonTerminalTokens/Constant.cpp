//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/Constant.h"

#include <string>

Constant::Constant(std::string buf) : name(std::move(buf)){

}

std::ostream &operator<<(std::ostream &os, const Constant &constant) {
    os << constant.name << "\t\t[CONSTANT]" ;
    return os;
}

void Constant::print(std::ostream &os) const {
    os << *this;
}
