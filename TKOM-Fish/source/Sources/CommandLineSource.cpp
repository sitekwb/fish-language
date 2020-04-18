//
// Created by Wojtek on 17/04/2020.
//

#include <iostream>
#include <Analizator/Lexer/Token.h>
#include "Sources/CommandLineSource.h"

char CommandLineSource::peek() {
    serve();
    return buf.peek();
}

char CommandLineSource::get() {
    serve();
    return buf.get();
}

void CommandLineSource::serve() {
    while(! buf.rdbuf()->in_avail()) {
        if(!last){
            last = true;
            break;
        }
        printPrompt();
        char line[MAX_LINE_LEN];
        std::cin.getline(line, MAX_LINE_LEN);
        std::stringstream().swap(buf);
        buf.str(line);
        last = false;
    }
}

void CommandLineSource::printPrompt() const {
    std::cout << "Fish> ";
    std::cout.flush();
}

void CommandLineSource::printDebug(TokenType const &tokenType, std::string const &value) {
    if(tokenType == ONE_SIGN){
        std::cout << Token(*this, value[0]);
    }
    else {
        std::cout << Token(tokenType, value);
    }

    std::cout.flush();
}

std::string CommandLineSource::exchangeToken(TokenType tokenType, std::string &value) const{
    if(tokenType == ONE_SIGN && value[0] == (char)EOF){
        std::string s;
        s.push_back('\n');
        return std::move(s);
    }
    if(tokenType == ONE_SIGN && value[0] == '$'){
        std::string s;
        s.push_back((char)EOF);
        return std::move(s);
    }
    return std::move(value);
}

CommandLineSource::CommandLineSource() : last(true) {

}
