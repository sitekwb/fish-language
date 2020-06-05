//
// Created by Wojtek on 16/04/2020.
//

#include <iostream>
#include <memory>
#include <Analizator/Nodes/File.h>
#include <Controller.h>
#include <Analizator/Parser/ParsingError.h>


using namespace std;

Controller::Controller(SourceUP source_)
        : lexer(make_unique<Lexer>(move(source_))) {

}

void Controller::execute() {
    try {
        Parser parser(*lexer);
        FileUP file = parser.parseFile();
        //TODO interpreter
    }
    catch (ParsingError &e) {
        std::cout << e.what();
    }
}