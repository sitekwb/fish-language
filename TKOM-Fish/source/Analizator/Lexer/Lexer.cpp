//
// Created by Wojtek on 14/04/2020.
//

#include <Src.h>
#include <Analizator/Lexer/Lexer.h>
#include <Analizator/Lexer/TokenType.h>
#include "../../../include/Exceptions/SecondPointException.h"

using namespace std;

Lexer::Lexer(unique_ptr<Context> context_, unique_ptr<Src> source_) : context(move(context_)), source(move(source_)),
                                                                      c(0), potentialType(IDENTIFIER) {

}


TokenT Lexer::getNextToken() {
    c = source->peek();
    while (c != EOF) {
        buf.clear();
        c = source->peek();
        if (isalpha(c)) {
            potentialType = IDENTIFIER;
            do {
                saveAndnext();
            } while (isalnum(c) || c == '_');
            auto keywordIterator = Token::keywords.find(buf);
            if (keywordIterator != Token::keywords.end()) {
                return make_unique<Token>(KEYWORD, buf);
            }
            return make_unique<Token>(IDENTIFIER, buf);
        } else if (c == '0') {
            potentialType = DBL;
            saveAndnext();
            if (c == '.') {
                saveAndnext();
                if (!isdigit(c)) {
                    throw std::runtime_error("No digit after point error");
                }
                do {
                    saveAndnext();
                } while (isdigit(c));
                return make_unique<Token>(DBL, buf);
            }
            return make_unique<Token>(INT, buf);
        }
            // another digit but no zero
        else if (isdigit(c)) {
            potentialType = INT;
            do {
                saveAndnext();
            } while (isdigit(c));
            if (c == '.') {
                saveAndnext();
                if (!isdigit(c)) {
                    throw std::runtime_error("No digit after point error");
                }
                do {
                    saveAndnext();
                } while (isdigit(c));
                return make_unique<Token>(DBL, buf);
            }
            return make_unique<Token>(INT, buf);
        } else if (isspace(c)) {
            next();
            continue;
        } else {
            switch (c) {
                // constant
                case '_':
                    potentialType = CONSTANT;
                    saveAndnext();
                    if (!isupper(c)) {
                        throw std::runtime_error("Single underscore error");
                    }
                    do {
                        saveAndnext();
                    } while (isupper(c));
                    return make_unique<Token>(CONSTANT, buf);
                case '"':
                    potentialType = STR;
                    next();
                    do {
                        saveAndnext();
                        if (c == '\\') {
                            next();
                            saveAndnext();
                        }
                    } while (c != '"');
                    next();
                    return make_unique<Token>(STR, buf);
                case '\'':
                    potentialType = STR;
                    next();
                    do {
                        saveAndnext();
                    } while (c != '\'');
                    next();
                    return make_unique<Token>(STR, buf);
                case '+':
                case '-':
                case '*':
                case '/':
                case '%':
                case '<':
                case '>':
                case '=':
                case '!':
                    potentialType = OPERATOR;
                    saveAndnext();
                    if (c == '=') {
                        saveAndnext();
                        return make_unique<Token>(OPERATOR, buf);
                    }
                    return make_unique<Token>(*source, buf[0]);
                case '.':
                case ',':
                case '{':
                case '[':
                case '(':
                case '}':
                case ']':
                case ')':
                case '$':
                case ';':
                    saveAndnext();
                    return make_unique<Token>(*source, buf[0]);
                default:
                    throw std::runtime_error("Unknown sign");
            }
        } // else
    } // while
    source->get();
    return make_unique<Token>(*source, (char) EOF);
}

void Lexer::saveAndnext() {
    save();
    next();
}

void Lexer::next() {
    if (source->get() == '\n') {
        context->nextLineNumber();
    }
    context->nextSignNumber();
    c = source->peek();
}

void Lexer::save() {
    buf += c;
    if (buf.length() > maxLength.at(potentialType)) {
        throw std::runtime_error("Too long string");
    }
}

const std::unique_ptr<Context> &Lexer::getContext() const {
    return context;
}

const SrcT &Lexer::getSource() const {
    return source;
}


