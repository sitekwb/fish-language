//
// Created by Wojtek on 27/05/2020.
//

#include "Analizator/Interpreter/Units/ArgumentList.h"

using namespace std;

ArgumentList::ArgumentList() {
    constructed = true;
    bool hasArguments = buildSymbol<Argument>(argumentOptional);
    if(hasArguments){
        while(buildRepeat());
    }
}

bool ArgumentList::buildRepeat() {
    TokenUPD comma;
    ArgumentUP argument;
    bool constructed = buildToken(",", comma)
            and buildSymbol<Argument>(argument);
    if(constructed){
        repeatListOptional.push_back({move(comma), move(argument)});
    }
    return constructed;
}

void ArgumentList::execute() {
    if(!constructed){
        return;
    }
    argumentOptional->execute();
    for(auto &e:repeatListOptional){
        // we don't execute first, because it's a token
        e.second->execute();
    }
}
