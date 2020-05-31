//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/SymbolNotFoundException.h>
#include "Analizator/Interpreter/Env.h"

using namespace std;


Env::Env(GlobalEnv &parentEnv_) : parentEnv(parentEnv_){

}

void Env::setGlobalSymbol(std::string name, Object &symbol) {
    // TODO logic what with existing
    parentEnv.hashMap[name] = symbol;
}

Object &Env::operator[](std::string name) {
    if(hashMap.count(name)){
        return hashMap[name];
    }
    if(parentEnv.isGlobalEnv() and not parentEnv.hashMap.count(name)){
        throw SymbolNotFoundException(name);
    }
    return static_cast<Env &>(parentEnv)[name];
}

bool Env::isGlobalEnv() const{
    return false;
}

void Env::destroySymbol(std::string name) {
    hashMap.erase(move(name));
}
