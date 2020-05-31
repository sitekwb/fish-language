//
// Created by Wojtek on 16/04/2020.
//

#ifndef FISH_PARSER_H
#define FISH_PARSER_H

#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <Analizator/Lexer.h>
#include <Analizator/Symbols/File.h>


class Parser {
public:
    Parser(LexerUP lexer);
    FileUP parseFile();
    FilePartUP parseFilePart();

};


#endif //FISH_PARSER_H
