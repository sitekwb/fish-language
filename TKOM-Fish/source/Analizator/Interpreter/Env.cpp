//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/SymbolNotFoundException.h>
#include "Analizator/Interpreter/Env.h"

using namespace std;


Env::Env(GlobalEnv &parentEnv_) : parentEnv(parentEnv_){

}

void Env::setGlobalSymbol(std::string name, std::reference_wrapper<Obj> object) {
    auto &globalEnv = parentEnv;
    while(not globalEnv.isGlobalEnv()){
        globalEnv = static_cast<Env &>(globalEnv).parentEnv;
    }
    if(globalEnv.hashMap.count(name)){
        //TODO if existing
    }
    globalEnv.hashMap.insert({move(name), object});
}

Obj &Env::operator[](std::string name) {
    auto it = hashMap.find(name);
    if(it != hashMap.end()){
        return it->second;
    }
    it = parentEnv.hashMap.find(name);
    if(parentEnv.isGlobalEnv() and it == parentEnv.hashMap.end()){
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
