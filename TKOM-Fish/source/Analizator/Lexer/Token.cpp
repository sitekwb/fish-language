//
// Created by Wojtek on 14/04/2020.
//

#include <sstream>
#include "../../../include/Analizator/Lexer/Token.h"
#include <iomanip>

using namespace std;

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Token &token) {
    os << setw(15) << token.value << "\t\t" << setw(10);

    switch (token.type) {
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
        case PLUS:
            os << '+';
            break;
        case MULTIPLY:
            os << '*';
            break;
        case DIVIDE:
            os << '/';
            break;
        case PERCENT:
            os << '%';
            break;
        case POINT:
            os << '.';
            break;
        case COMMA:
            os << ',';
            break;
        case BLOCK_OPEN:
            os << '{';
            break;
        case BLOCK_CLOSE:
            os << '}';
            break;
        case SQUARE_OPEN:
            os << '[';
            break;
        case SQUARE_CLOSE:
            os << ']';
            break;
        case BRACKET_OPEN:
            os << '(';
            break;
        case BRACKET_CLOSE:
            os << ')';
            break;
        case EQUAL:
            os << '=';
            break;
        case LESS:
            os << '<';
            break;
        case MORE:
            os << '>';
            break;
        case SEMICOLON:
            os << ';';
            break;
        case EOF_TOKEN:
            os << "[EOF]";
            break;
        case PLUS_EQ:
            os << "+=";
            break;
        case MINUS_EQ:
            os << "-=";
            break;
        case MULTIPLY_EQ:
            os << "*=";
            break;
        case DIVIDE_EQ:
            os << "/=";
            break;
        case PERCENT_EQ:
            os << "%=";
            break;
        case LESS_EQ:
            os << "<=";
            break;
        case MORE_EQ:
            os << ">=";
            break;
        case EQ_EQ:
            os << "==";
            break;
        case NOT_EQ:
            os << "!=";
            break;
        case MINUS:
            os << "-";
            break;
    }
    os << std::endl;
    return os;
}

bool Token::operator==(const Token &token) const {
    if(type == KEYWORD){
        return type == token.type && value == token.value;
    }
    return type == token.type;
}

Token::Token(TokenType tokenType, std::string val, Context context_)
        : type(tokenType), value(val), context(context_) {
//    // check if tokens are valid
//    switch (type) {
//        case INT:
//            // throws exceptions if incompatible value
//            stoi(val);
//            break;
//        case DBL:
//            stod(val);
//            break;
//        case IDENTIFIER:
//            if (!isalpha(val[0])) {
//                throw std::runtime_error("Identifier not starting with letter");
//            }
//            break;
//        case CONSTANT:
//            if (val.length() < 2 || val[0] != '_' || !isupper(val[1])) {
//                throw std::runtime_error("Constant error");
//            }
//            break;
//        case KEYWORD:
//            if (keywords.count(val) != 1) {
//                throw std::runtime_error("Keyword error");
//            }
//            break;
//        case STR:
//            break;
//        default:
//            if (val.length() != 0) {
//                throw std::runtime_error("Non empty token value with operator or one-sign token");
//            }
//            break;
//    }
}

TokenType Token::getType() const {
    return type;
}

const std::string &Token::getValue() const {
    return value;
}

std::unique_ptr<Token> Token::buildKeyword(const std::string &buf) {
    auto keywordIterator = Token::keywords.find(buf);
    if (keywordIterator != Token::keywords.end()) {
        return std::make_unique<Token>(KEYWORD, buf);
    }
    return nullptr;
}

bool Token::isTwoSignTokenSign(char c) {
    auto signIterator = operatorFirstSigns.find(c);
    return signIterator != operatorFirstSigns.end();
}

bool Token::isSignToken(char c) {
    auto signIterator = oneSigns.find(c);
    return signIterator != oneSigns.end();
}

TokenType Token::getTwoSignTokenType(char c) {
    switch (c) {
        case '+':
            return PLUS_EQ;
        case '-':
            return MINUS_EQ;
        case '*':
            return MULTIPLY_EQ;
        case '/':
            return DIVIDE_EQ;
        case '%':
            return PERCENT_EQ;
        case '<':
            return LESS_EQ;
        case '>':
            return MORE_EQ;
        case '=':
            return EQ_EQ;
        case '!':
            return NOT_EQ;
        default:
            throw std::runtime_error("no operator starting from this sign");
    }
}

TokenType Token::getOneSignTokenType(char c) {
    switch (c) {
        case '+':
            return PLUS;
        case '-':
            return MINUS;
        case '*':
            return MULTIPLY;
        case '/':
            return DIVIDE;
        case '%':
            return PERCENT;
        case '.':
            return POINT;
        case ',':
            return COMMA;
        case '{':
            return BLOCK_OPEN;
        case '}':
            return BLOCK_CLOSE;
        case '[':
            return SQUARE_OPEN;
        case ']':
            return SQUARE_CLOSE;
        case '(':
            return BRACKET_OPEN;
        case ')':
            return BRACKET_CLOSE;
        case '=':
            return EQUAL;
        case '<':
            return LESS;
        case '>':
            return MORE;
        case ';':
            return SEMICOLON;
        case EOF:
            return EOF_TOKEN;
        case '!':
            return NOT;
        case ':':
            return COLON;
        default:
            throw std::runtime_error("no one sign token from this sign"+to_string(c));
    }
}

Token::Token(char c) {
    type = getOneSignTokenType(c);
}

Token::Token(string tokenValue) : value(move(tokenValue)) {
    if(value.size() == 1){
        type = getOneSignTokenType(value[0]);
        value = "";
    }
    else if(value.size() == 2 && value.ends_with('=') && isTwoSignTokenSign(value[0])){
        type = getTwoSignTokenType(value[0]);
        value = "";
    }
    else if(keywords.count(value)){
        type = KEYWORD;
    }
    else{
        type = IDENTIFIER;
    }
}

bool Token::operator==(const TokenType &rhs) const {
    return type == rhs;
}

bool Token::operator!=(const TokenType &rhs) const {
    return ! (*this == rhs);
}

const std::string Token::getErrorMessage() const {
    return "Parsing error with token value '"+getValue()
    +"' at line "+to_string(context.getLineNumber())
    +" and sign "+to_string(context.getSignNumberInLine())+".";
}


