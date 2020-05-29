//
// Created by Wojtek on 16/04/2020.
//

#include <iostream>
#include <memory>
#include <Analizator/Interpreter/Interpreter.h>
#include <Analizator/Interpreter/EndOfFileException.h>
#include "Controller.h"


using namespace std;

Controller::Controller(Source &source_, bool debug, bool isFileSource_) : source(source_),
                                                                          isDebug(debug),
                                                                          isFileSource(isFileSource_),
                                                                          parser(make_unique<Parser>(
                                                                                  make_unique<Lexer>(source_))) {
}

void Controller::execute() {
    FileUP file;
    FilePartUP filePart;
    try {
        if (isFileSource) {
            file = parser->parseFile();
            file->execute();
        } else {
            do {
                filePart = parser->parseFilePart();
                filePart->execute();
            } while (true);
        }
    }
    catch (EndOfFileException &e) {

    }
    catch (Token &token) {
        cout << token.getErrorMessage();
    }
}
