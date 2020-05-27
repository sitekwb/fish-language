//
// Created by Wojtek on 16/04/2020.
//

#include <iostream>
#include <memory>
#include <Analizator/Interpreter/Interpreter.h>
#include "Controller.h"


using namespace std;

Controller::Controller(std::unique_ptr<Source> source, bool debug) : isDebug(debug) {
    lexer = make_unique<Lexer>(unique_ptr<Source>(move(source)));
    parser = make_unique<Parser>();
    interpreter = make_unique<Interpreter>();
}

void Controller::execute() {
    Token eof = Token(EOF_TOKEN);
    TokenUP token;
    try{
        do {
            token = lexer->getNextToken();
            printDebug(*token);
            if(parser->parse(*token)) {
                interpreter->interprete(*parser);
            }
        } while (*token != eof);
    }
    catch (Token &token) {
        cout << token.getErrorMessage();
    }
}

void Controller::printDebug(const Token &token) {
    if (isDebug) {
        std::cout << token << std::endl;
        std::cout.flush();
    }
}
