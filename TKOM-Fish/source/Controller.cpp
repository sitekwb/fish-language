//
// Created by Wojtek on 16/04/2020.
//

#include <iostream>
#include <memory>
#include <Analizator/EndOfFileException.h>
#include <Analizator/Symbols/File.h>
#include <Controller.h>
#include <Analizator/Interpreter/NotImplementedException.h>
#include <Analizator/Interpreter/SymbolNotFoundException.h>


using namespace std;

Controller::Controller(SourceUP source_) :source(move(source_)){
    parser = make_unique<Parser>(
            make_unique<Lexer>(*source));

}

void Controller::execute() {
    try {
        Env env;
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
    catch(NotImplementedException &e){
        std::cout << "Not implemented exception";
    }
    catch(SymbolNotFoundException &e){
        std::cout << "SymbolNotFoundException";
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
