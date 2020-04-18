//
// Created by Wojtek on 16/04/2020.
//

#include <Analizator/Parser/LanguageParser.h>
#include <Analizator/Lexer/TokenType.h>
#include <iostream>
#include <memory>
#include "Controller.h"


using namespace std;

Controller::Controller(std::unique_ptr<Src> source) {
    lexer = make_unique<Lexer>(make_unique<Context>(), unique_ptr<Src>(move(source)));
    parser = make_unique<LanguageParser>();
}

void Controller::analise() {
    auto token = lexer->getNextToken();
    lexer->getSource()->printDebug(token->getType(), token->getValue());
    auto eof = (char)EOF;
    while (*token != eof) {
        token = lexer->getNextToken();
        lexer->getSource()->printDebug(token->getType(), token->getValue());
        parser->parse();
    }
}
