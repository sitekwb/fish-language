//
// Created by Wojtek on 27/05/2020.
//


#include <Analizator/Symbols/ArgumentList.h>

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

void ArgumentList::execute(Env &env) {
    if(!constructed){
        return;
    }
    if(argumentOptional) {
        argumentOptional->execute(env);
        objectList.push_back(argumentOptional->getObject());
    }
    for(auto &e:repeatListOptional){
        // we don't execute first, because it's a token
        e.second->execute(env);
        objectList.push_back(e.second->getObject());
    }
    evaluateList();
}


ArgumentList::ArgumentList(ArgumentList &list) {
    objectList = list.objectList;
    evaluateList();
}


ArgumentList::ArgumentList(int) {

}

ObjectType ArgumentList::getObjectType() const {
    return ObjectType::OT_ArgumentList;
}

int ArgumentList::getSize() const {
    return objectList.size();
}
