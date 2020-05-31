//
// Created by Wojtek on 16/04/2020.
//

#include "Analizator/Parser.h"
#include <iostream>
#include <Analizator/Symbols/File.h>

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


