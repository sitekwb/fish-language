//
// Created by Wojtek on 16/04/2020.
//

#include "Analizator/Parser/Parser.h"
#include <iostream>
#include <Analizator/Interpreter/Units/File.h>

using namespace std;

Parser::Parser(LexerUP lexer){
    Symbol::setLexer(move(lexer));
}

FileUP Parser::parseFile() {
    return make_unique<File>();
}

FilePartUP Parser::parseFilePart() {
    return make_unique<FilePart>();
}


