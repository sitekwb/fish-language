//
// Created by Wojtek on 27/05/2020.
//

#include <Analizator/EndOfFileException.h>
#include "Analizator/Symbols/File.h"

using namespace std;

File::File() {
    try {
        FilePartUP filePart;
        while (buildSymbol<FilePart>(filePart)) {
            filePartList.push_back(move(filePart));
        }
        throw *Symbol::getNextToken();
    }
    catch(EndOfFileException &e){

    }
}

void File::execute(Env &env) {
    if (!constructed) {
        return;
    }

    for (auto &e: filePartList) {
        e->execute(env);
    }
    //done
}

