//
// Created by Wojtek on 14/04/2020.
//

#include <sstream>
#include "Analizator/Tokens/Token.h"
#include <iomanip>

using namespace std;

bool Token::operator!=(const Token &rhs) const {
    return !(rhs == *this);
}

bool Token::operator==(const Token &token) const {
    if (type == KEYWORD) {
        return type == token.type && value == token.value;
    }
    return type == token.type;
}

Token::Token(TokenType tokenType, std::string val, Context context_)
        : type(tokenType), value(val), context(context_) {

}

TokenType Token::getType() const {
    return type;
}

const std::string &Token::getValue() const {
    return value;
}

std::unique_ptr<Token> Token::buildKeyword(const std::string &buf, Context &context) {
    auto keywordIterator = Token::keywords.find(buf);
    if (keywordIterator != Token::keywords.end()) {
        return std::make_unique<Token>(KEYWORD, buf, context);
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

Token::Token(char c, Context context_) : context(context_){
    type = getOneSignTokenType(c);
}

Token::Token(string tokenValue, Context context_) : value(move(tokenValue)), context(context_) {
    if (value.size() == 1 and isSignToken(value[0])) {
        type = getOneSignTokenType(value[0]);
        value = "";
    } else if (value.size() == 2 && value.ends_with('=') && isTwoSignTokenSign(value[0])) {
        type = getTwoSignTokenType(value[0]);
        value = "";
    } else if (keywords.count(value)) {
        type = KEYWORD;
    } else {
        type = IDENTIFIER;
    }
}

bool Token::operator==(const TokenType &rhs) const {
    return type == rhs;
}

bool Token::operator!=(const TokenType &rhs) const {
    return !(*this == rhs);
}

const std::string Token::getErrorMessage() const {
    return "Parsing error with token (" + getTypeString() + ", " + getValue()
           + ") at line " + to_string(context.getLineNumber())
           + " and sign " + to_string(context.getSignNumberInLine()) + ".";
}

Token::Token(TokenType tokenType, Context context) : Token(tokenType, "", context){

}

const std::string Token::getTypeString() const {
    switch (type) {
        case STR:
            return "[STR]";
            break;
        case INT:
            return "[INT]";
            break;
        case DBL:
            return "[DBL]";
            break;
        case IDENTIFIER:
            return "[IDENTIFIER]";
            break;
        case CONSTANT:
            return "[CONSTANT]";
            break;
        case KEYWORD:
            return "[KEYWORD]";
            break;
        case PLUS:
            return "+";
            break;
        case MULTIPLY:
            return "*";
            break;
        case DIVIDE:
            return "/";
            break;
        case PERCENT:
            return "%";
            break;
        case POINT:
            return ".";
            break;
        case COMMA:
            return ",";
            break;
        case BLOCK_OPEN:
            return "{";
            break;
        case BLOCK_CLOSE:
            return "}";
            break;
        case SQUARE_OPEN:
            return "[";
            break;
        case SQUARE_CLOSE:
            return "]";
            break;
        case BRACKET_OPEN:
            return "(";
            break;
        case BRACKET_CLOSE:
            return ")";
            break;
        case EQUAL:
            return "=";
            break;
        case LESS:
            return "<";
            break;
        case MORE:
            return ">";
            break;
        case SEMICOLON:
            return ";";
            break;
        case EOF_TOKEN:
            return "[EOF]";
            break;
        case PLUS_EQ:
            return "+=";
            break;
        case MINUS_EQ:
            return "-=";
            break;
        case MULTIPLY_EQ:
            return "*=";
            break;
        case DIVIDE_EQ:
            return "/=";
            break;
        case PERCENT_EQ:
            return "%=";
            break;
        case LESS_EQ:
            return "<=";
            break;
        case MORE_EQ:
            return ">=";
            break;
        case EQ_EQ:
            return "==";
            break;
        case NOT_EQ:
            return "!=";
            break;
        case MINUS:
            return "-";
            break;
        case NOT:
            return "!";
            break;
        case COLON:
            return ":";
            break;
        default:
            return "other";
    }
}

Context Token::getContext() const {
    return context;
}

ObjectType Token::getObjectType() const {
    switch(type){
        case STR:
            return ObjectType::OT_STRING;
        case INT:
            return ObjectType::OT_INT;
        case DBL:
            return ObjectType::OT_DOUBLE;
        case IDENTIFIER:
            return ObjectType::OT_IDENTIFIER;
        case CONSTANT:
            return ObjectType::OT_CONSTANT;
        case KEYWORD:
            return ObjectType::OT_KEYWORD;
        default:
            return ObjectType::OT_TOKEN;
    }
}


