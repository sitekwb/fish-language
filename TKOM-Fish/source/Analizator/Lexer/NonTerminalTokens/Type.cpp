//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/Type.h"

Type::Type(std::string name_) : name(std::move(name_)){

}

std::ostream &operator<<(std::ostream &os, const Type &type) {
    os << type.name << "\t\t[TYPE]";
    return os;
}

void Type::print(std::ostream &os) const {
    os << *this;
}

