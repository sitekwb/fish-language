//
// Created by Wojtek on 14/04/2020.
//

#include <sstream>
#include "../../../include/Analizator/Lexer/Token.h"

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    token.print(os);
    return os;
}

bool Token::operator==(const Token &rhs) const {
    std::stringstream s1, s2;
    this->print(s1);
    rhs.print(s2);
    return s1.str() == s2.str();
}
