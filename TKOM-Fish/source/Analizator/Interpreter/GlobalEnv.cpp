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

void GlobalEnv::setSymbol(std::string name, std::reference_wrapper<Obj> object) {
    if(hashMap.find(name) != hashMap.end()){
        //TODO if existing
    }
    hashMap.insert({move(name), object});
}

Obj & GlobalEnv::operator[](std::string name) {
    if(hashMap.count(name)){
        return hashMap.at(std::move(name));
    }
    throw SymbolNotFoundException(name);
}
