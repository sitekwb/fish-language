//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/SymbolNotFoundException.h>
#include "Analizator/Interpreter/GlobalEnv.h"

bool GlobalEnv::isGlobalEnv() const{
    return true;
}

GlobalEnv &GlobalEnv::operator=(GlobalEnv &other) {
    hashMap = other.hashMap;
    return *this;
}

void GlobalEnv::setSymbol(std::string name, Object &object) {
// TODO warning if existing
    hashMap[name] = object;
}

Object & GlobalEnv::operator[](std::string name) {
    if(hashMap.count(name)){
        return hashMap[name];
    }
    throw SymbolNotFoundException(name);
}
