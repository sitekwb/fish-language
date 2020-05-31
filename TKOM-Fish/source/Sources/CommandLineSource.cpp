//
// Created by Wojtek on 17/04/2020.
//

#include <iostream>
#include <Analizator/Tokens/Token.h>
#include "Sources/CommandLineSource.h"

using namespace std;

char CommandLineSource::peek() {
    serve();
    return exchangeEOF(buf.peek());
}

char CommandLineSource::get() {
    return exchangeEOF(buf.get());
}

void CommandLineSource::serve(bool isString) {
    bool needNew = ! buf.rdbuf()->in_avail();
    if(needNew && !last){
        last = true;
        needNew = false;
    }
    if(initialisation || needNew) {
        last = false;
        initialisation = false;

        (isString) ? printStringPrompt() : printPrompt();
        std::string str;
        std::getline(std::cin, str);
        std::stringstream().swap(buf);
        buf.str(str);
        // Try to finish
        if(!isString && *(--(str.end())) == FINISH_SIGN){
            exit(0);
        }
    }
}

void CommandLineSource::printPrompt() const {
    std::cout << "Fish> ";
    std::cout.flush();
}

void CommandLineSource::printStringPrompt() const {
    std::cout << "> ";
    std::cout.flush();
}

CommandLineSource::CommandLineSource() : last(true), initialisation(true) {

}

char CommandLineSource::getStringSign() {
    return exchangeEOF(buf.get());
}

char CommandLineSource::peekStringSign() {
    serve(true);
    return exchangeEOF(buf.peek());
}

char CommandLineSource::exchangeEOF(char c) {
    return (c == EOF) ? '\n' : c;
}

bool CommandLineSource::isFileSource() const{
    return false;
}
