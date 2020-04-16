//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/Dbl.h"

Dbl::Dbl(double dbl) : value(dbl){

}

Dbl::Dbl(std::string const &buf) : value(stod(buf)){

}

std::ostream &operator<<(std::ostream &os, const Dbl &dbl) {
    os << dbl.value << "\t\t[DBL]";
    return os;
}

void Dbl::print(std::ostream &os) const {
    os << *this;
}
