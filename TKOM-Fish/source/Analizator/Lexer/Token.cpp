//
// Created by Wojtek on 14/04/2020.
//

#include <sstream>
#include "../../../include/Analizator/Lexer/Token.h"

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << token.value << "\t\t";

    switch (token.type) {
        case ONE_SIGN:
            os << "[ONE_SIGN]";
            break;
        case STR:
            os << "[STR]";
            break;
        case INT:
            os << "[INT]";
            break;
        case DBL:
            os << "[DBL]";
            break;
        case IDENTIFIER:
            os << "[IDENTIFIER]";
            break;
        case CONSTANT:
            os << "[CONSTANT]";
            break;
        case KEYWORD:
            os << "[KEYWORD]";
            break;
        case OPERATOR:
            os << "[OPERATOR]";
            break;
    }
    os << std::endl;
    return os;
}

bool Token::operator==(const Token &rhs) const {
    return this->type == rhs.type && this->value == rhs.value;
}

Token::Token(TokenType tokenType, std::string val) : type(tokenType), value(val) {
    // check if tokens are valid
    switch (type) {
        case ONE_SIGN:
            throw std::runtime_error("Wrong constructor to one sign");
            break;
        case INT:
            // throws exceptions if incompatible value
            stoi(val);
            break;
        case DBL:
            stod(val);
            break;
        case IDENTIFIER:
            if (!isalpha(val[0])){
                throw std::runtime_error("Identifier not starting with letter");
            }
                break;
        case CONSTANT:
            if(val.length() < 2 || val[0] != '_' || !isupper(val[1])){
                throw std::runtime_error("Constant error");
            }
            break;
        case KEYWORD:
            if (keywords.count(val) != 1) {
                throw std::runtime_error("Keyword error");
            }
            break;
        case OPERATOR:
            if (operators.count(val) != 1) {
                throw std::runtime_error("Keyword error");
            }
            break;
        default:
            break;
    }
}

Token::Token(Src const &source, char c) : type(ONE_SIGN), value() {
    value.push_back(c);
    value = source.exchangeToken(type, value);
}

TokenType Token::getType() const {
    return type;
}

const std::string &Token::getValue() const {
    return value;
}

bool Token::operator!=(const char &rhs) const {
    return !(*this == rhs);
}

bool Token::operator==(const char &rhs) const {
    return this->type == ONE_SIGN && this->value[0] == rhs;
}
