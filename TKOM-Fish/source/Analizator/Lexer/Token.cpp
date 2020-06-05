//
// Created by Wojtek on 14/04/2020.
//

#include <sstream>
#include "Analizator/Lexer/Token.h"
#include <iomanip>

using namespace std;


Token::Token(TokenType tokenType, Context context) : Token(tokenType, "", context) {

}


Token::Token(char c, Context context_) : context(context_) {
    type = getOneSignTokenType(c);
}

Token::Token(TokenVariant &tokenVariant, Context context_) : value(move(tokenVariant)), context(context_) {
    if(get_if<bool>(&value)){
        type = BOOL;
    }
    else if(get_if<double>(&value)){
        type = DBL;
    }
    else if(get_if<int>(&value)){
        type = INT;
    }
    else if(auto s = get_if<string>(&value)) {
        string &str = *s;
        if (str.size() == 1 and isSignToken(str[0])) {
            type = getOneSignTokenType(str[0]);
            value = "";
        } else if (str.size() == 2 && str.ends_with('=') && isTwoSignTokenSign(str[0])) {
            type = getTwoSignTokenType(str[0]);
            value = "";
        } else if (keywords.find(str) != keywords.end()) {
            type = KEYWORD;
        } else {
            type = IDENTIFIER;
        }
    }
}

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}

bool Token::operator==(const Token &token) const {
    if (type == KEYWORD) {
        return type == token.type && value == token.value;
    }
    return type == token.type;
}


bool Token::operator==(const TokenType &rhs) const {
    return type == rhs;
}

bool Token::operator!=(const TokenType &rhs) const {
    return !(*this == rhs);
}




TokenType Token::getType() const {
    return type;
}


std::unique_ptr<Token> Token::buildKeyword(const TokenVariant &v, Context &context) {
    if(auto keyword = get_if<string>(&v)) {
        if (keywords.find(*keyword) != keywords.end()) {
            string str = get<string>(v);
            return std::make_unique<Token>(KEYWORD, str, context);
        }
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
            throw std::runtime_error("no one sign token from this sign" + to_string(c));
    }
}

const std::string Token::getErrorMessage() const {

    return "Parsing error with token (" + getTypeString() + ", " + getStringValue()
           + ") at line " + to_string(context.getLineNumber())
           + " and sign " + to_string(context.getSignNumberInLine()) + ". ";
}



const std::string Token::getStringValue() const {
    if(auto str = get_if<string>(&value)){
        return *str;
    }
    if(auto b = get_if<bool>(&value)){
        return (*b) ? "true" : "false";
    }
    if(auto num = get_if<double>(&value)) {
        return to_string(*num);
    }
    if(auto num = get_if<int>(&value)){
        return to_string(*num);
    }
    throw runtime_error("Get string value error");
}

const std::string Token::getTypeString() const {
    switch (type) {
        case STR:
            return "[STR]";
        case INT:
            return "[INT]";
        case DBL:
            return "[DBL]";
        case IDENTIFIER:
            return "[IDENTIFIER]";
        case CONSTANT:
            return "[CONSTANT]";
        case KEYWORD:
            return "[KEYWORD]";
        case PLUS:
            return "+";
        case MULTIPLY:
            return "*";
        case DIVIDE:
            return "/";
        case PERCENT:
            return "%";
        case POINT:
            return ".";
        case COMMA:
            return ",";
        case BLOCK_OPEN:
            return "{";
        case BLOCK_CLOSE:
            return "}";
        case SQUARE_OPEN:
            return "[";
        case SQUARE_CLOSE:
            return "]";
        case BRACKET_OPEN:
            return "(";
        case BRACKET_CLOSE:
            return ")";
        case EQUAL:
            return "=";
        case LESS:
            return "<";
        case MORE:
            return ">";
        case SEMICOLON:
            return ";";
        case EOF_TOKEN:
            return "[EOF]";
        case PLUS_EQ:
            return "+=";
        case MINUS_EQ:
            return "-=";
        case MULTIPLY_EQ:
            return "*=";
        case DIVIDE_EQ:
            return "/=";
        case PERCENT_EQ:
            return "%=";
        case LESS_EQ:
            return "<=";
        case MORE_EQ:
            return ">=";
        case EQ_EQ:
            return "==";
        case NOT_EQ:
            return "!=";
        case MINUS:
            return "-";
        case NOT:
            return "!";
        case COLON:
            return ":";
        case BOOL:
            return "BOOL";
    }
}

const TokenVariant &Token::getValue() const {
    return value;
}

Token::Token(TokenType tokenType, std::string &tokenValue, Context context)
        : type(move(tokenType)), value(move(tokenValue)), context(move(context)){

}

Token::Token(TokenType tokenType, int tokenValue, Context context)
        : type(move(tokenType)), value(move(tokenValue)), context(move(context)){

}
Token::Token(TokenType tokenType, double tokenValue, Context context)
        : type(move(tokenType)), value(move(tokenValue)), context(move(context)){

}
Token::Token(TokenType tokenType, bool tokenValue, Context context)
        : type(move(tokenType)), value(move(tokenValue)), context(move(context)){

}

bool Token::operator==(const std::string &rhs) const{
    if(auto v = get_if<string>(&value)){
        return *v == rhs;
    }
    return false;
}
//bool Token::operator==(const bool &rhs) const{
//    if(auto v = get_if<bool>(&value)){
//        return *v == rhs;
//    }
//    return false;
//}
//bool Token::operator==(const int &rhs) const{
//    if(auto v = get_if<int>(&value)){
//        return *v == rhs;
//    }
//    return false;
//}
//bool Token::operator==(const double &rhs) const{
//    if(auto v = get_if<double>(&value)){
//        return *v == rhs;
//    }
//    return false;
//}

bool Token::operator!=(const std::string &rhs) const{
    return not(*this == rhs);
}
//bool Token::operator!=(const bool &rhs) const{
//    return not(*this == rhs);
//}
//bool Token::operator!=(const int &rhs) const{
//    return not(*this == rhs);
//}
//bool Token::operator!=(const double &rhs) const{
//    return not(*this == rhs);
//}
