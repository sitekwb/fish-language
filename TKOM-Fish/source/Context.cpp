//
// Created by Wojtek on 14/04/2020.
//

#include "Context.h"

Context::Context() : lineNumber(0), signNumber(0), signNumberInLine(0) {

}

void Context::nextLineNumber() {
    ++lineNumber;
    signNumberInLine = 0;
}

void Context::nextSignNumber() {
    ++signNumber;
    ++signNumberInLine;
}

unsigned int Context::getLineNumber() const {
    return lineNumber;
}

unsigned int Context::getSignNumber() const {
    return signNumber;
}

unsigned int Context::getSignNumberInLine() const {
    return signNumberInLine;
}

Context::Context(unsigned int lineNumber_, unsigned int signNumber_, unsigned int signNumberInLine_)
: lineNumber(lineNumber_), signNumber(signNumber_), signNumberInLine(signNumberInLine_){

}
