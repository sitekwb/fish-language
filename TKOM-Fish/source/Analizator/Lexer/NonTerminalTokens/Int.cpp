//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/Int.h"

Int::Int(const std::string &buf) : value(std::stoi(buf)){

}

Int::Int(int val) : value(val){}

std::ostream &operator<<(std::ostream &os, const Int &anInt) {
    os << anInt.value << "\t\t[INT]";
    return os;
}

void Int::print(std::ostream &os) const {
    os << *this;
}
