//
// Created by Wojtek on 31/05/2020.
//

#include <Analizator/Interpreter/SymbolNotFoundException.h>
#include "Analizator/Interpreter/Env.h"

using namespace std;


Env::Env(Env &parentEnv_) : parent(parentEnv_){

}

void Env::setGlobalSymbol(std::string name, std::reference_wrapper<Obj> object) {
    auto &prec = parent;
    while(not prec.isGlobal){
        prec = prec.parent;
    }
    prec.setSymbol(move(name), move(object));
}

Obj &Env::operator[](std::string name) {
    auto it = hashMap.find(name);
    if(it != hashMap.end()){
        return it->second;
    }
    it = parent.hashMap.find(name);
    if(parent.isGlobal and it == parent.hashMap.end()){
        throw SymbolNotFoundException(name);
    }
    return parent[name];
}

void Env::destroySymbol(std::string name) {
    if(hashMap.find(name) != hashMap.end()) {
        hashMap.erase(move(name));
    }
    if(isGlobal){
        return;
    }
    parent.destroySymbol(move(name));
}

Env::Env() : isGlobal(true), parent(*this){

}

Env &Env::operator=(Env &other) {
    hashMap = other.hashMap;
    return *this;
}

void Env::setSymbol(std::string name, std::reference_wrapper<Obj> object) {
    if(hashMap.find(name) != hashMap.end()){
        //TODO if existing
    }
    hashMap.insert({move(name), object});
}