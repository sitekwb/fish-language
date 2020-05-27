//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/File.h"

File::File(Lexer &lexer) : Symbol(lexer) {
    while(buildFilePart());
}

bool File::buildFilePart() {
    filePartList.push_back(FilePart());
    return filePartList.back().isConstructed();
}

void File::execute() {
    if(isConstructed()) {
        for (auto &e: filePartList) {
            e.execute();
        }
    }
}
