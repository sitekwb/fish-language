//
// Created by Wojtek on 15/04/2020.
//

#include "../../../../include/Analizator/Lexer/NonTerminalTokens/Variable.h"

Variable::Variable(std::string name_) : name(std::move(name_)) {

}

std::ostream &operator<<(std::ostream &os, const Variable &variable) {
    os << variable.name << "\t\t[VARIABLE]";
    return os;
}

void Variable::print(std::ostream &os) const {
    os << *this;
}
