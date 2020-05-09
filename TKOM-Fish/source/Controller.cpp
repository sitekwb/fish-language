//
// Created by Wojtek on 16/04/2020.
//

#include <iostream>
#include <memory>
#include "Controller.h"


using namespace std;

Controller::Controller(std::unique_ptr<Source> source, bool debug) : isDebug(debug){
    lexer = make_unique<Lexer>(unique_ptr<Source>(move(source)));
    parser = make_unique<Parser>();
}

void Controller::execute() {
    Token eof = Token(EOF_TOKEN);
    TokenUP token;
    do {
        token = lexer->getNextToken();
        printDebug(*token);
        parser->parse(*token);
    } while (*token != eof);
}

void Controller::printDebug(const Token &token) {
    if(isDebug) {
        std::cout << token << std::endl;
        std::cout.flush();
    }
}
