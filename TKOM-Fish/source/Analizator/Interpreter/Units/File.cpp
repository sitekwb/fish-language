//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/File.h"

File::File() {
    FilePartUP filePart;
    while (buildSymbol<FilePart>(filePart)) {
        filePartList.push_back(move(filePart));
    }
}

void File::execute() {
    if (!constructed) {
        return;
    }
    for (auto &e: filePartList) {
        e->execute();
    }
}

