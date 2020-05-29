//
// Created by Wojtek on 14/04/2020.
//

#include <Source.h>
#include <Analizator/Lexer/Lexer.h>
#include <Analizator/Lexer/TokenType.h>
#include "../../../include/Exceptions/SecondPointException.h"

using namespace std;

Lexer::Lexer(Source &source_)
        : context(), source(source_), c(0) {

}


TokenUP Lexer::getNextToken() {
    buf.clear();
    c = source.peek();
    while (isspace(c)) {
        next();
    }

    if (buildLetterToken()) {
        return move(currentToken);
    }
    if (buildNumberToken()) {
        return move(currentToken);
    }
    if (buildConstantToken()) {
        return move(currentToken);
    }
    if (buildStringToken()) {
        return move(currentToken);
    }
    if (buildSignToken()) {
        return move(currentToken);
    }

    throw std::runtime_error("unknown token");
}

bool Lexer::buildConstantToken() {
    if (c != '_') {
        return false;
    }
    collect();
    if (!isupper(c)) {
        throw std::runtime_error("single underscore");
    }
    collectUpperLetters();

    currentToken = make_unique<Token>(CONSTANT, buf);
    return true;
}

bool Lexer::buildStringToken() {
    if (c != '"' && c != '\'') {
        return false;
    }
    // is string (') or escapedString (")
    char startSign = c;

    nextStringSign();

    (startSign == '"') ? collectEscapedString() : collectString();

    next();

    currentToken = make_unique<Token>(STR, buf);
    return true;
}

bool Lexer::buildSignToken() {
    if (!Token::isSignToken(c)) {
        return false;
    }
    char sign = c;
    collect();
    // is two sign token?
    if (!Token::isTwoSignTokenSign(sign) || c != '=') {
        // one sign
        currentToken = make_unique<Token>(Token::getOneSignTokenType(sign));
        return true;
    }
    // two
    collect(); // collect '=' sign
    currentToken = make_unique<Token>(Token::getTwoSignTokenType(sign));
    return true;
}

void Lexer::collect() {
    save();
    next();
}

void Lexer::next() {
    if (source.get() == '\n') {
        context.nextLineNumber();
    }
    context.nextSignNumber();
    c = source.peek();
}

void Lexer::save() {
    buf += c;
}

const Source &Lexer::getSource() const {
    return source;
}

bool Lexer::buildLetterToken() {
    if (!isalpha(c)) {
        return false;
    }
    collectIdentifier();
    currentToken = Token::buildKeyword(buf);
    if (currentToken) {
        return true;
    }
    currentToken = make_unique<Token>(IDENTIFIER, buf);
    return true;
}

bool Lexer::buildNumberToken() {
    if (!isdigit(c)) {
        return false;
    }
    // Is number

    // First digit?
    if (c == '0') {
        // One sign 0 integer
        collect();
    } else {
        // Many digits integer
        collectDigits();
    }

    // Is double?
    if (c == '.') {
        collect();
        return buildDoubleToken();
    }

    // It is integer and not double
    currentToken = make_unique<Token>(INT, buf);
    return true;
}

void Lexer::collectDigits() {
    do {
        collect();
    } while (isdigit(c));
}

bool Lexer::buildDoubleToken() {
    if (!isdigit(c)) {
        throw std::runtime_error("no digit after point");
    }
    collectDigits();
    currentToken = make_unique<Token>(DBL, buf);
    return true;
}

void Lexer::collectUpperLetters() {
    do {
        collect();
    } while (isupper(c));
}

void Lexer::collectEscapedString() {
    while (c != '"') {
        if (c == '\\') {
            nextStringSign();
        }
        collectStringSign();
    }
}

void Lexer::collectString() {
    do {
        collectStringSign();
    } while (c != '\'');
}

void Lexer::collectIdentifier() {
    do {
        collect();
    } while (isalnum(c) || c == '_');
}

void Lexer::collectStringSign() {
    save();
    nextStringSign();
}

void Lexer::nextStringSign() {
    source.getStringSign();
    c = source.peekStringSign();
}

Lexer &Lexer::operator=(const Lexer &l) {
    context = l.context;
    source = l.source;
    buf = l.buf;
    c = l.c;
    currentToken = make_unique<Token>(*(l.currentToken));
    return *this;
}

