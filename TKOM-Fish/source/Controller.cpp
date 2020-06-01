//
// Created by Wojtek on 16/04/2020.
//

#include <iostream>
#include <memory>
#include <Analizator/EndOfFileException.h>
#include <Analizator/Symbols/File.h>
#include <Controller.h>


using namespace std;

Controller::Controller(SourceUP source_) :source(move(source_)){
    parser = make_unique<Parser>(
            make_unique<Lexer>(*source));

}

void Controller::execute() {
    try {
        GlobalEnv globalEnv;
        Env env(globalEnv);
        if (source->isFileSource()) {
            FileUP file;
            file = parser->parseFile();
            file->execute(env);
            resetFile(file);
        } else {
            do {
                FilePartUP filePart;
                filePart = parser->parseFilePart();
                filePart->execute(env);
                resetFilePart(filePart);
            } while (true);
        }
    }
    catch (EndOfFileException &e) {
        // we discovered end of file
    }
    catch (Token &token) {
        cout << token.getErrorMessage();
    }
}

void Controller::resetFile(FileUP &file) {
    TokenDeleter::setTokenSaving(false);
    file.reset();
    TokenDeleter::setTokenSaving(true);
}

void Controller::resetFilePart(FilePartUP &filePart) {
    TokenDeleter::setTokenSaving(false);
    filePart.reset();
    TokenDeleter::setTokenSaving(true);
}
