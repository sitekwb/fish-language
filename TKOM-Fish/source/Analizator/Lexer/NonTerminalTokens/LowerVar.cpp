//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/LowerVar.h"

LowerVar::LowerVar(std::string name_) : Variable(std::move(name_)) {

}

std::ostream &operator<<(std::ostream &os, const LowerVar &var) {
    os << static_cast<const Variable &>(var) << "\t[LOWERVAR]";
    return os;
}

void LowerVar::print(std::ostream &os) const {
    os << *this;
}
