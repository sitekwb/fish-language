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
    argumentOptional->execute(env);
    objectList.push_back(argumentOptional->getReturnObject());
    for(auto &e:repeatListOptional){
        // we don't execute first, because it's a token
        e.second->execute(env);
        objectList.push_back(e.second->getReturnObject());
    }
}


ArgumentList::ArgumentList(ArgumentList &list) {
    objectList = list.objectList;
}


ArgumentList::ArgumentList(int) {

}

ObjectType ArgumentList::getObjectType() const {
    return ObjectType::OT_ArgumentList;
}

int ArgumentList::getInt() const{
    return objectList.size();
}

std::list<Object &> &ArgumentList::getList() {
    return objectList;
}
