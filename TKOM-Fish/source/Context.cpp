//
// Created by Wojtek on 14/04/2020.
//

#include "Context.h"

Context::Context() : line(0), sign(0), signInLine(0) {

}

void Context::nextLine() {
    ++line;
    signInLine = 0;
}

void Context::nextSign() {
    ++sign;
    ++signInLine;
}

unsigned int Context::getLine() const {
    return line;
}

unsigned int Context::getSign() const {
    return sign;
}

unsigned int Context::getSignInLine() const {
    return signInLine;
}
