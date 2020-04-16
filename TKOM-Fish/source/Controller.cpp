//
// Created by Wojtek on 16/04/2020.
//

#include <Analizator/Parser/Parser.h>
#include <Analizator/Lexer/TerminalToken.h>
#include <iostream>
#include "Controller.h"

Controller::Controller() : context() {
    lexer = LexerT(new Lexer(context));
    parser = ParserT(new Parser(context));
}

void Controller::analise(std::istream &is, std::ostream &os) {
    auto token = TokenT(new TerminalToken(PLUS));
    while (*token != TerminalToken(DOLLAR)) {
        token = TokenT(new TerminalToken(PLUS));
        printPrompt(os);
        while (*token != TerminalToken(NEWLINE) && *token != TerminalToken(DOLLAR)) {
            token = std::move(lexer->getNextToken(is));
            printTokenDebug(os, *token);
        }
    }
}

void Controller::printTokenDebug(std::ostream &os, Token const &token) const {
    std::cout << token << std::endl;
    std::cout.flush();
}

void Controller::printPrompt(std::ostream &os) const {
    os << "Fish> ";
    os.flush();
}
